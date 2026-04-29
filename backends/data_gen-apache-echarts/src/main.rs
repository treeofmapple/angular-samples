use std::net::SocketAddr;

use axum::serve;
use gauss::config::routes::define_access_routes;
use tokio::{net::TcpListener, signal};

#[tokio::main]
async fn main() -> anyhow::Result<()> {
    let define_routes = define_access_routes().await;

    let addr = SocketAddr::from(([127, 0, 0, 1], 8000));
    println!("Servidor rodando em http://{}", addr);

    let listener = TcpListener::bind(addr).await?;

    serve(listener, define_routes)
        .with_graceful_shutdown(async {
            signal::ctrl_c().await.expect("Failed to listen for Ctrl+c");
            println!("\nEncerrando Servidor...");
        })
        .await?;
    Ok(())
}
