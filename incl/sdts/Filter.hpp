#ifndef FILTER_HPP
#define FILTER_HPP

#include "sdts/InputSignal.hpp"
#include "sdts/OutputSignal.hpp"

namespace sdts
{
    template <typename Number, int XSize, int YSize, typename Functor>
    struct _Filter
    {
        Functor func;
        InputSignal<Number,XSize> Xseries;
        OutputSignal<Number,YSize> Yseries;
        
        _Filter(Functor f) : func(f){}

        Number operator()(Number xin)
        {
            Xseries.push(xin);
            Yseries.shift();
            func(Xseries, Yseries);
            auto result = Yseries[0];
            return result;
        }
    };


    template <typename Number, int XSize, int YSize>
    struct Filter{
        template<typename Functor>
        static auto CreateFilter(Functor f)
        {
            return _Filter<Number, XSize, YSize, Functor>(f);
        }
    };
}
#endif // #ifndef FILTER_HPP