#ifndef OUTPUTSIGNAL_HPP
#define OUTPUTSIGNAL_HPP

namespace sdts
{
    template<typename Number, int Ysize>
    struct OutputSignal
    {
        std::array<Number,Ysize> _output{0};

        void shift()
        {
            Number pass_to_next;
            Number from_prev = 0;

            for(auto& out: _output)
            {
                pass_to_next = out;
                out = from_prev;
                from_prev = pass_to_next;
            }
        }
        // 3  2  1  0 -1 -2 -3
        // 0  0  0  0  1  2  3
        auto& operator[](int n)
        {
            if(n < 0)
            {
                auto N = (-1* n);
                return _output[N];
            }
            return _output[0];
        }

        Number& operator=(Number val)
        {
            _output[0] = val;
            return _output[0];
        }
    };
}

#endif // #ifndef OUTPUTSIGNAL_HPP