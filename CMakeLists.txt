cmake_minimum_required(VERSION 3.17)
project(dae_solver)

set(CMAKE_CXX_STANDARD 14)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_subdirectory(Google_tests)

add_library(dae_solver ElastanceDenormalizer.cpp ElastanceDenormalizer.h ElastanceData.h Parameters.cpp Parameters.h DAEModel.cpp DAEModel.h Solver.cpp Solver.h)

target_link_libraries (dae_solver Eigen3::Eigen)