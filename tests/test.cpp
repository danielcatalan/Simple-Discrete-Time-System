#include <gtest/gtest.h>
#include "sdts/Filter.hpp"
#include <algorithm>


TEST(TestSuite, StraightThrough)
{
    auto filter = sdts::Filter<float,1,1>::CreateFilter([n=0](const auto& x, auto& y)
    {
        y[n] = x[n];
    });

    std::array<float,5> xin{1,2,3,4,5};
    std::array<float,5> yout;

    std::transform(xin.begin(), xin.end(), yout.begin(), filter);

    EXPECT_EQ(xin, yout);
}

TEST(TestSuite, MovingAverage)
{
    auto filter = sdts::Filter<double,4,1>::CreateFilter([n=0](const auto& x, auto& y)
    {
        y[n] = 0.25*(x[n] + x[n-1] + x[n-2] + x[n-3]);
    });

    std::array<double,6> xin      = {0.00, 1.00, 1.00, 1.00, 1.00, 1.00};
    std::array<double,6> expected = {0.00, 0.25, 0.50, 0.75, 1.00, 1.00};
    
    std::array<double,6> yout;

    std::transform(xin.begin(), xin.end(), yout.begin(), filter);

    EXPECT_EQ(expected, yout);
}

