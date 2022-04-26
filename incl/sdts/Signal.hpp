#ifndef SIGNAL_HPP
#define SIGNAL_HPP

#include <array>

namespace sdts
{
    template<typename Number, int Size>
    class Signal
    {
    protected:
        std::array<Number,Size> _signal{0};
        int zero_index = Size-1;

        constexpr int GetCorrectedIndex(int n) const
        {
            if(n<0)
            {
                return (Size + zero_index + n) % Size;
            }
            return zero_index;
        }
        
    public:

        constexpr auto& operator[](int n) const
        {
            auto I = GetCorrectedIndex(n);
            return _signal[I];
        }

        constexpr auto& operator[](int n)
        {
            auto I = GetCorrectedIndex(n);
            return _signal[I];
        }

        operator Number() const
        {
            return _signal[0];
        }
    };
}

#endif // #ifndef SIGNAL_HPP
