#ifndef INPUTSIGNAL_HPP
#define INPUTSIGNAL_HPP

#include "sdts/Signal.hpp"

namespace sdts
{
    template<typename Number, int Xsize>
    class InputSignal : public Signal<Number, Xsize>
    {   
    public:
        void push(Number x)
        {
            this->zero_index = (this->zero_index + 1) % Xsize;

            this->_signal[this->zero_index] = x;
        }
    };
}
#endif // #ifndef INPUTSIGNAL_HPP