cmake_minimum_required(VERSION 3.10)  # specify minimum CMake version

project(ARIMA)  # your project name - this defines PROJECT_SOURCE_DIR

# Now you can use PROJECT_SOURCE_DIR
include_directories(${PROJECT_SOURCE_DIR}/include)

# Rest of your CMake configuration...
add_executable(arima
    src/main.cpp
    src/TimeSeriesData.cpp
    src/ARIMAModel.cpp
    src/ModelOptimizer.cpp
)
target_include_directories(arima PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${eigen_SOURCE_DIR}
)
include_directories(${PROJECT_SOURCE_DIR}/include)
