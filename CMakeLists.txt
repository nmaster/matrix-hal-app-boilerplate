project(matrix-app C CXX)
cmake_minimum_required(VERSION 2.8)

set (matrix-app_VERSION_MAJOR 1)
set (matrix-app_VERSION_MINOR 0)

add_definitions(-std=c++11)

# Enable extra warnings by uncommenting next line.
# ADM_EXTRA_WARNINGS()

# Find packages and libs required by MATRIX Creator HAL
FIND_PACKAGE(Threads)
FIND_LIBRARY (FFTW_LIBRARIES NAMES fftw3f )
FIND_LIBRARY(WIRINGPI_LIB NAMES wiringPi)
FIND_LIBRARY(WIRINGPI_DEV_LIB NAMES wiringPiDev)
FIND_LIBRARY(CRYPT_LIB NAMES crypt)

# Add executable for MATRIX Creator HAL app.
add_executable(matrix-app ./cpp/matrix-app.cpp)
  set_property(TARGET matrix-app PROPERTY CXX_STANDARD 11)
  target_link_libraries(matrix-app matrix_creator_hal)
  target_link_libraries(matrix-app ${CMAKE_THREAD_LIBS_INIT})
