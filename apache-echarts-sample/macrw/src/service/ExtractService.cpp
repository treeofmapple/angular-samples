#include "../model/DataChart.h"

void DataChartService::load_data_if_empty() {
  if (global_df.empty()) {
    global_df.read("spotify_songs.csv", io_format::csv2);
  }
}
