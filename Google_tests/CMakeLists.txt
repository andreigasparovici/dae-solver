project(Google_tests)
add_subdirectory(lib)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_executable(Google_Tests_run test.cpp)

target_link_libraries(Google_Tests_run gtest gtest_main dae_solver Eigen3::Eigen)