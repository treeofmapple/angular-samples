use serde::Serialize;

#[derive(Serialize, Debug)]
pub struct MusicData {
    pub track_popularity: Option<String>,
    pub playlist_genre: Option<String>,
    pub playlist_subgenre: Option<String>,
    pub key: Option<String>,
    pub loudness: Option<String>,
    pub acousticness: Option<String>,
    pub duration_ms: Option<String>,
}
