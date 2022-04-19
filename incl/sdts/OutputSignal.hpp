#ifndef OUTPUTSIGNAL_HPP
#define OUTPUTSIGNAL_HPP

namespace sdts
{
    template<typename Number, int Ysize>
    class OutputSignal
    {
        std::array<Number,Ysize> _output{0};
        int zero_index = 0;
        
    public:
        void shift()
        {
            zero_index = (zero_index + 1) % Ysize;
        }
        // 3  2  1  0 -1 -2 -3
        // 0  0  0  0  1  2  3
        auto& operator[](int n)
        {
            if(n < 0)
            {
                auto I = (Ysize + zero_index + n) % Ysize;
                return _output[I];
            }
            return _output[zero_index];
        }

        Number& operator=(Number val)
        {
            _output[zero_index] = val;
            return _output[zero_index];
        }
    };
}

#endif // #ifndef OUTPUTSIGNAL_HPP