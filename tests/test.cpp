#include <gtest/gtest.h>
#include "sdts/Filter.hpp"
#include <algorithm>


TEST(TestSuite, StraightThrough)
{
    auto filter = sdts::Filter<1,1,float>::CreateFilter([n=0](const auto& x, auto& y)
    {
        y[n] = x[n];
    });

    std::array<float,5> xin{1,2,3,4,5};
    std::array<float,5> yout;

    std::transform(xin.begin(), xin.end(), yout.begin(), filter);

    EXPECT_EQ(xin, yout);
}


TEST(TestSuite, Delay)
{
    auto filter = sdts::Filter<2,1>::CreateFilter([n=0](const auto& x, auto& y)
    {
        y[n] = x[n-1];
    });

    std::array<double,6> xin      = {1,2,3,4,5,6};
    std::array<double,6> expected = {0,1,2,3,4,5};
    
    std::array<double,6> yout;

    std::transform(xin.begin(), xin.end(), yout.begin(), filter);

    EXPECT_EQ(expected, yout);
}


TEST(TestSuite, MovingAverage)
{
    auto filter = sdts::Filter<4,1>::CreateFilter([n=0](const auto& x, auto& y)
    {
        y[n] = 0.25*(x[n] + x[n-1] + x[n-2] + x[n-3]);
    });

    std::array<double,6> xin      = {0.00, 1.00, 1.00, 1.00, 1.00, 1.00};
    std::array<double,6> expected = {0.00, 0.25, 0.50, 0.75, 1.00, 1.00};
    
    std::array<double,6> yout;

    std::transform(xin.begin(), xin.end(), yout.begin(), filter);

    EXPECT_EQ(expected, yout);
}


TEST(TestSuite, YFeedback)
{
    // Use Exponential Smoothing
    double alpha = 0.9;
    auto filter = sdts::Filter<1,2>::CreateFilter([n=0,&alpha](const auto& x, auto& y)
    {
        y[n] = alpha*x[n] + (1-alpha)*y[n-1];
    });

    std::array<double,6> xin      = {0.00, 1.00, 1.00, 1.00, 1.00, 1.00};
    std::array<double,6> expected = {0.00, 0.90, 0.99, 0.999, 0.9999, 0.99999};
    
    std::array<double,6> yout;


    std::transform(xin.begin(), xin.end(), yout.begin(), filter);

    EXPECT_EQ(expected, yout);
}

