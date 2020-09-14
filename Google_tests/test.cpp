//
// Created by andrei on 25.08.2020.
//

#include "gtest/gtest.h"

#include <iostream>

#include "../DAEModel.h"
#include "../Solver.h"

TEST(DummyTest, Positive) {
    Vector<double, SIZE> x0{};
    DAEModel model(0, x0);

    Solver solver;
    auto u = solver.solveAt(model, 1);
    std::cout << u;
}
