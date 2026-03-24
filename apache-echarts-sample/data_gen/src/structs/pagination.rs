use serde::Deserialize;

#[derive(Deserialize, Debug)]
pub struct Pagination {
  pub offset: i64,
  pub limit: u32,
}
