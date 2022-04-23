#ifndef OUTPUTSIGNAL_HPP
#define OUTPUTSIGNAL_HPP

#include "sdts/Signal.hpp"

namespace sdts
{
    template<typename Number, int Ysize>
    class OutputSignal : public Signal<Number,Ysize>
    {
    public:
        void shift()
        {
            auto& zero_index  = this->zero_index;
            zero_index = (zero_index + 1) % Ysize;
        }

        Number& operator=(Number val)
        {
            auto& zero_index  = this->zero_index;
            auto& _signal = this->_signal;

            _signal[zero_index] = val;
            return _signal[zero_index];
        }
    };
}

#endif // #ifndef OUTPUTSIGNAL_HPP