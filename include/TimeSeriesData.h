#pragma once
#include <vector>

class TimeSeriesData
{
    public:
        TimeSeriesData(std::vector<double> data, int d);
        std::vector<double> difference(const int order = 1) const;
        std::vector<double> inverse_difference(const std::vector<double>& diff_data, const std::vector<double>& original) const;
        void SetOrder(const int d);
        int GetOrder() const;
        void SetData(std::vector<double> data);
        std::vector<double> GetData() const;

    private:
        std::vector<double> data;
        int d; // Order of differencing
};
