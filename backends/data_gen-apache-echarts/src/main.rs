#[tokio::main]
async fn main() {
  let app = Router::new().route("/data", get(get_chart_data));
  let listener = tokio::net::TcpListener::bind("127.0.0.1:3000").await.unwrap();
  println!("Listening on http://127.0.0.1:3000/data?offset=0&limit=5000");
  axum::serve(listener, app).await.unwrap();
}
