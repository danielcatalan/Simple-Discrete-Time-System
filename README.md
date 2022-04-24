# Simple-Discrete-Time-System #

Simple discrete time system library for c++. This library aims to simplify the creation of a discrete time system or filter.

## Simple Example ##
Lets say we want to implement the following filter:

![equation](https://latex.codecogs.com/png.image?\inline&space;\dpi{110}\bg{white}y[n]=0.9\times&space;x[n]&plus;0.1\times&space;y[n-1])

We can implement the filter using the difference equation in c++ as follows:

```c++
auto filter1 = sdts::Filter<float, 1, 2>::CreateFilter([n=0](const auto& x, auto& y)
{
    y[n] = 0.9*x[n] + 0.1*y[n-1];
});
```

What is created is a function object that can be used with algorithm library or for loops:

```c++
std::array<float, N> xin {/* Input signal data*/};
std::array<float, N> yout;

// Using algorithm library
std::transform(xin.begin(), xin.end(), yout.begin(), filter1);


// Using for loop
for(auto i=0; i < N; i++)
{
    yout[i] = filter1(xin[i]);
}
```
