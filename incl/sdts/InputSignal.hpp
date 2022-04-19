#ifndef INPUTSIGNAL_HPP
#define INPUTSIGNAL_HPP

namespace sdts
{
    template<typename Number, int Xsize>
    struct InputSignal
    {
        std::array<Number,Xsize> _input{0};

        void push(Number x)
        {
            Number pass_to_next;
            Number from_prev = x;

            for(auto& in: _input)
            {
                pass_to_next = in;
                in = from_prev;
                from_prev = pass_to_next;
            }
        }

        auto& operator[](int n) const
        {
            if(n < 0)
            {
                auto N = -1* n;
                return _input[N];
            }
            return _input[0];
        }

        operator Number() const
        {
            return _input[0];
        }
    };
}
#endif // #ifndef INPUTSIGNAL_HPP