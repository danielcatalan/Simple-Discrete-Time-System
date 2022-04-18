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