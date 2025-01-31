#include<vector>
int main() {
    // Sample data
    std::vector<double> data = {1.0, 2.1, 3.2, 4.1, 5.3};

    // Create and fit ARIMA(1,1,1) model
    ARIMAModel model(1, 1, 1);
    model.fit(data);

    // Make predictions
    auto predictions = model.predict(3);

    return 0;
}
