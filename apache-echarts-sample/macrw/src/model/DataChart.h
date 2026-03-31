#pragma once
#include <cstddef>
#include <cstdint>
#include <DataFrame/DataFrame.h>

using namespace hmdf;

struct ChartDataResult {
    StdDataFrame<uint64_t> data_view;
    size_t page;
    size_t total_count;
};

class DataChartService {
private:
    StdDataFrame<uint64_t> global_df;

public:
    ChartDataResult get_paginated_data(size_t offset, size_t limit);

};
