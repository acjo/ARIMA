#include "TimeSeriesData.h"

TimeSeriesData::TimeSeriesData(std::vector<double> data, int d) {
  this->data = data;
  this->d = d;
}

// Compute differences of the time series
std::vector<double> TimeSeriesData::difference(const int order) const {
  std::vector<double> diff_data = data;
  for (int i = 0; i < order; ++i) {
    std::vector<double> temp;
    for (size_t j = 1; j < diff_data.size(); ++j) {
      temp.push_back(diff_data[j] - diff_data[j - 1]);
    }
    diff_data = temp;
  }
  return diff_data;
}

// Reverse differencing to get original scale predictions
std::vector<double> TimeSeriesData::inverse_difference(
    const std::vector<double>& diff_data,
    const std::vector<double>& original) const {
  std::vector<double> result = diff_data;
  for (int i = d; i > 0; --i) {
    std::vector<double> temp(result.size());
    temp[0] = original[original.size() - i] + result[0];
    for (size_t j = 1; j < result.size(); ++j) {
      temp[j] = temp[j - 1] + result[j];
    }
    result = temp;
  }
  return result;
}

void TimeSeriesData::SetOrder(const int d){
  this->d = d;
}

int TimeSeriesData::GetOrder() const {
  return d;
}

void TimeSeriesData::SetData(const std::vector<double> data){
  this->data = data;
}

std::vector<double> TimeSeriesData::GetData() const {
  return data;
}

