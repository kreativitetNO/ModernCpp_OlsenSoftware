#ifndef UTILS_H
#define UTILS_H

#include <string>

template <typename T>
constexpr std::string get_type(T t)
{
	return typeid(t).name();
}

template <typename T>
constexpr T adder(T const& val)
{
	return val;
}

template <typename T, typename... Args>
constexpr T adder(T const& first, Args const&... args)
{
	return first + adder(args...);
}

template <typename T>
constexpr bool pair_comparer(T const& first, T const& second)
{
	return first == second;
}

template <typename T, typename... Args>
constexpr bool pair_comparer(T const& first, T const& second, Args... args)
{
	return (first == second) && pair_comparer(args...);
}

#endif