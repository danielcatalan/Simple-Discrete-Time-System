#ifndef INPUTSIGNAL_HPP
#define INPUTSIGNAL_HPP

namespace sdts
{
    template<typename Number, int Xsize>
    class InputSignal
    {
        std::array<Number,Xsize> _input{0};
        int zero_index = 0;
        
    public:
        void push(Number x)
        {
            zero_index = (zero_index + 1) % Xsize;

            _input[zero_index] = x;
        }

        auto& operator[](int n) const
        {
            auto I = (Xsize + zero_index + n) % Xsize;
            return _input[I];
        }

        operator Number() const
        {
            return _input[0];
        }
    };
}
#endif // #ifndef INPUTSIGNAL_HPP