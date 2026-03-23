use minmaxlttb::{Point, lttb, Binning};
use axum::{Json, Router, extract::Query, routing::get};
use polars::prelude::{LazyCsvReader, LazyFileListReader, col};
use serde::Deserialize;

#[derive(Deserialize)]
struct Pagination {
  offset: i64,
  limit: u32,
}

async fn get_chart_data (Query(pagination): Query<Pagination>) -> Json<Vec<[f64; 2]>> {
  let df = LazyCsvReader::new("spotify_songs.csv")
    .finish()
    .unwrap()
    .slice(pagination.offset, pagination.limit)
    .select([col("tempo"), col("energy")])
    .collect()
    .unwrap();

  let tempo_col = df.column("tempo").unwrap().f64().unwrap();
  let energy_col = df.column("energy").unwrap().f64().unwrap();

  let raw_points: Vec<Point> = tempo_col
    .into_iter()
    .zip(energy_col.into_iter())
    .filter_map(|(x, y)| Some(Point::new(x?, y?)))
    .collect();

  let downsampled = lttb(&raw_points, 1000, Binning::ByCount).unwrap();

  let response: Vec<[f64; 2]> = downsampled
    .into_iter()
    .map(|p| [p.x(), p.y()])
    .collect();

  Json(response)
}

#[tokio::main]
async fn main() {
  let app = Router::new().route("/data", get(get_chart_data));
  let listener = tokio::net::TcpListener::bind("127.0.0.1:3000").await.unwrap();
  println!("Listening on http://127.0.0.1:3000/data?offset=0&limit=5000");
  axum::serve(listener, app).await.unwrap();
}
