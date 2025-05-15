#include <iostream>
#include <functional>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;
using namespace std::placeholders;

auto add = [](const auto first, const auto second) { return first + second; };

template<typename T, T one> auto increment = bind(add, _1, one);
TEST_CASE("Increments"){
		CHECK_EQ(43, increment<int, 1>(42));
}