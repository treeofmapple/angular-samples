use axum::{Router, routing::get};

use crate::{config::cors::insert_cors_config, operations::extract::get_chart_data};

pub async fn define_access_routes() -> Router {
    Router::new()
        .route("/data", get(get_chart_data))
        .layer(insert_cors_config())
}
