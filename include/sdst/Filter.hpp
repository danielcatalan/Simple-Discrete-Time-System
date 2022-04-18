#ifndef FILTER_HPP
#define FILTER_HPP

namespace sdst
{
    template <typename Number, int XSize, int YSize, typename Functor>
    struct _Filter
    {
        Functor func;
        InputSignal<Number,XSize> Xseries;
        OutputSignal<Number,YSize> Yseries;
        
        _Filter(Functor f) : func(f){}

        float operator()(float xin)
        {
            Xseries.push(xin);
            func(Xseries, Yseries);
            auto result = Yseries[0];
            Yseries.shift();
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