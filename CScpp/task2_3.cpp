/*
Напишите шаблонную функцию to_pair, которая принимает произвольный std::tuple и два индекса внутри и возвращает std::pair, содержащий элементы переданного std::tuple с соответствующими индексами.

Пример:

auto t = std::make_tuple(0, 3.5, "Hello");
std::pair<double, char const *> p = to_pair<1,2>(t);
// p содержит 3.5 и "Hello"
 */

#include <iostream>
#include <tuple>

template<int firstIndex, int secondIndex, typename... Tup>
auto to_pair(std::tuple<Tup...> tpl)->decltype(std::make_pair(std::get<firstIndex>(tpl), std::get<secondIndex>(tpl))) {
    return std::make_pair(std::get<firstIndex>(tpl), std::get<secondIndex>(tpl));
}

auto t = std::make_tuple(0, 3.5, "Hello");
std::pair<double, char const *> p = to_pair<1,2>(t);
