use minmaxlttb::{Point, lttb, Binning};
use axum::{Json, Router, routing::get};
use polars::prelude::{LazyCsvReader, LazyFileListReader, col};
use serde::Deserialize;

#[derive(Deserialize)]
struct Pagination {
  offset: usize,
  limit: usize,
}

async fn get_chart_data () -> Json<Vec<[f64; 2]>> {
  let df = LazyCsvReader::new("spotify_songs.csv")
    .finish().unwrap()
    .select([col("tempo"), col("energy")])
    .collect().unwrap();

  let raw_points: Vec<Point> = df.column("tempo").unwrap().f64().unwrap()
    .into_iter()
    .zip(df.column("energy").unwrap().f64().unwrap())
    .map(|(x, y)| Point::new(x.unwrap(), y.unwrap()))
    .collect();

  let downsampled = lttb(&raw_points, 1000, Binning::ByCount).unwrap();

  let response = downsampled.iter().map(|p| [p.x(), p.y()]).collect();
  Json(response)
}

#[tokio::main]
async fn main() {
  let app = Router::new().route("/data", get(get_chart_data));
  let listener = tokio::net::TcpListener::bind("127.0.0.1:3000").await.unwrap();
  axum::serve(listener, app).await.unwrap();
}
