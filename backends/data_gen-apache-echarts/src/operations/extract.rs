use axum::{Json, extract::Query};
use log::{error, info};
use minmaxlttb::{Binning, Point, lttb};
use polars::prelude::{LazyCsvReader, LazyFileListReader, col};

use crate::models::pagination::Pagination;

pub async fn get_chart_data(Query(pagination): Query<Pagination>) -> Json<Vec<[f64; 2]>> {
    // Load your dataset
    let file_path = "/path/to/your/dataset.csv";
    let df = CsvReader::from_file(file_path)?
        .infer_schema(None)
        .has_header(true)
        .finish()
        .expect("Error reading CSV");

    // Sort the DataFrame by 'tempo' in ascending order
    let sorted_df = df.sort(["tempo"], false, true).expect("Error sorting DataFrame");

    let mut points: Vec<Point> = vec![];

    for row in sorted_df.iter_rows() {
        if let [Ok(tempo), Ok(popularity)] = [&row[9], &row[5]] { // 9 is 'tempo', 5 is 'popularity'
            points.push(Point::new(*tempo as f64, *popularity as f64));
        }
    }

    let downsampled_points = lttb(&points, 100).expect("Error during downsampling");

    Json(downsampled_points)
}
