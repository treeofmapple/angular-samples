use axum::{Json, extract::Query};
use minmaxlttb::{Binning, Point, lttb};
use polars::prelude::{LazyCsvReader, LazyFileListReader, col};

use crate::models::pagination::Pagination;

pub async fn get_chart_data(Query(pagination): Query<Pagination>) -> Json<Vec<[f64; 2]>> {
  let df = LazyCsvReader::new("spotify_songs.csv")
    .finish()
    .unwrap()
    .slice(pagination.offset, pagination.limit)
    .select([col("track_popularity"), col("playlist_genre"), col("playlist_subgenre"), col("key"), col("loudness"), col("accousticness"), col("duration_ms")])
    .collect()
    .unwrap();

  let response:

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
