# Simple-Discrete-Time-System

Simple discrete time system library for c++. This library aims to simplify the creation of a discrete time system or filter.
Lets say we want to implement the following filter:

![equation](https://latex.codecogs.com/svg.image?y[n]=0.9\times%20x[n]+0.1\times%20y[n-1])

We can implement the filter using the difference equation in c++ as follows:
```c++
auto filter1 = sdst::Filter<float, 1, 2>::CreateFilter([n=0](const auto& x, auto& y)
{
    y[n] = 0.9*x[n] + 0.1*y[n-1];
});
```
What is created is a functor that can be used with algorithm library or for loops:
```c++
std::array<float, N> xin {/* Input signal data*/};
std::array<float, N> yout;

// Using algorithm library
std::transform(xin.begin(), xin.end(), yout.begin(), filter1);


// Using for loop
for(auto i=0; i < xin.size(); i++)
{
    yout[i] = filter1(xin[i]);
}
```