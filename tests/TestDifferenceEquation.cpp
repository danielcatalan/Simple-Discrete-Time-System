#include "sdts/Filter.hpp"
#include <gtest/gtest.h>



constexpr auto DoFilter(const std::array<double,6>& xin)
{
    // Use Exponential Smoothing
    auto filter = sdts::Filter<1,2>::CreateFilter([n=0](const auto& x, auto& y)
    {
        y[n] = 0.9*x[n] + (0.1)*y[n-1];
    });

    std::array<double,6> yout = filter.filt(xin);

    return yout;
}

TEST(DifferenceEquation, filt)
{

    constexpr std::array<double,6> xin = {0.00, 1.00, 1.00, 1.00, 1.00, 1.00};
    std::array<double,6> expected      = {0.00, 0.90, 0.99, 0.999, 0.9999, 0.99999};
    
    static constexpr auto yout = DoFilter(xin);

    EXPECT_EQ(expected, yout);
}