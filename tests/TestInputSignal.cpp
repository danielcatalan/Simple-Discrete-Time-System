#include <gtest/gtest.h>
#include "sdts/InputSignal.hpp"

template<int Size>
class UnitTestInputsignal : public sdts::InputSignal<double,Size>
{
public:
    auto& GetArrary() const
    {
        return this->_signal;
    }
};


TEST(InpuSignal, ElementPlacement)
{
    UnitTestInputsignal<5> x;
    auto expected = std::array<double,5> {2,4,6,8,10};
    
    x.push(2);
    x.push(4);
    x.push(6);
    x.push(8);
    x.push(10);

    auto result = x.GetArrary();
    EXPECT_EQ( expected, result);

    EXPECT_EQ(10, x[0]);
    EXPECT_EQ(8, x[-1]);
    EXPECT_EQ(6, x[-2]);
    EXPECT_EQ(4, x[-3]);
    EXPECT_EQ(2, x[-4]);

    x.push(12);
    EXPECT_EQ(12, x[0]);
    EXPECT_EQ(10, x[-1]);
    EXPECT_EQ(8, x[-2]);
    EXPECT_EQ(6, x[-3]);
    EXPECT_EQ(4, x[-4]);
    
}

