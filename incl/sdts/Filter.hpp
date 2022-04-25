#ifndef FILTER_HPP
#define FILTER_HPP

#include "sdts/InputSignal.hpp"
#include "sdts/OutputSignal.hpp"

namespace sdts
{
    /**
     * @brief Class to represent a difference equation as a function object
     * 
     * @tparam Number numerical base type. prefer to use double or float.
     * @tparam XSize size of array that holds previous and current input values
     * @tparam YSize size of array that holds previous and current output values
     * @tparam Functor class of functor to be implemented
     */
    template <typename Number, int XSize, int YSize, typename Functor>
    class DifferenceEquation
    {
        Functor func;
        InputSignal<Number,XSize> Xseries;
        OutputSignal<Number,YSize> Yseries;
    
    public:
        constexpr DifferenceEquation(Functor f) : func(f){}

        constexpr Number operator()(Number xin)
        {
            Xseries.push(xin);
            Yseries.shift();
            func(Xseries, Yseries);
            auto result = Yseries[0];
            return result;
        }
    };

    /**
     * @brief Filter creator class.
     * 
     * @tparam XSize size of array to hold previous x-values.
     * @tparam YSize size of array to hold previous y-values.
     * @tparam Number Some numerical type. Prefer using double or float.
     */
    template <int XSize, int YSize, typename Number=double>
    struct Filter{
        template<typename Functor>
        static constexpr auto CreateFilter(Functor f)
        {
            return DifferenceEquation<Number, XSize, YSize, Functor>(f);
        }
    };
}
#endif // #ifndef FILTER_HPP
