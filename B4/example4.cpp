#include <iostream>
#include <string>
#include <functional>
#include <numeric>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <vector>

using namespace std;
using namespace std::placeholders;

/* Red 1
auto reverse_vector = []<typename T>(const std::vector<T> &input) -> std::vector<T>
{
    int i = input.size();
    i++;
    return {};
};

TEST_CASE("reverse vector")
{
    auto input = std::vector{1, 2, 3, 4, 5};
    auto expected = std::vector{5, 4, 3, 2, 1};
    auto original = input;
    auto result = reverse_vector(input);

    CHECK(result == expected);
    CHECK(input == original);
}

Green 1
auto reverse_vector = []<typename T>(const std::vector<T> &input) -> std::vector<T>
{
    int i = input.size();
    i++;
    return {5, 4, 3, 2, 1};
};

TEST_CASE("reverse vector")
{
    auto input = std::vector{1, 2, 3, 4, 5};
    auto expected = std::vector{5, 4, 3, 2, 1};
    auto original = input;
    auto result = reverse_vector(input);

    CHECK(result == expected);
    CHECK(input == original);
}


auto reverse_vector = []<typename T>(const std::vector<T> &input) -> std::vector<T>
{
    int i = input.size();
    i++;
    return {5, 4, 3, 2, 1};
};

TEST_CASE("reverse vector")
{
    struct TestData
    {
        std::vector<int> original_vector;
        std::vector<int> expected_vector;
    } data;

    SUBCASE("1 bis 5")
    {
        data.original_vector = std::vector{1, 2, 3, 4, 5};
        data.expected_vector = std::vector{5, 4, 3, 2, 1};
    }
    SUBCASE("1 bis 6")
    {
        data.original_vector = std::vector{1, 2, 3, 4, 5, 6};
        data.expected_vector = std::vector{6, 5, 4, 3, 2, 1};
    }

    CAPTURE(data);
    auto copy = data.original_vector;
    auto result = reverse_vector(data.original_vector);

    CHECK(result == data.expected_vector);
    CHECK(copy == data.original_vector);
}
*/

auto reverse_vector = []<typename T>(const std::vector<T> &input)
{
    std::vector<T> output;
    output.reserve(input.size());

    std::ranges::reverse_copy(input, std::back_inserter(output));
    return output;
};

TEST_CASE("reverse vector int")
{
    struct TestData
    {
        std::vector<int> original_vector;
        std::vector<int> expected_vector;
    } data;

    SUBCASE("1 bis 5")
    {
        data.original_vector = std::vector{1, 2, 3, 4, 5};
        data.expected_vector = std::vector{5, 4, 3, 2, 1};
    }
    SUBCASE("1 bis 6")
    {
        data.original_vector = std::vector{1, 2, 3, 4, 5, 6};
        data.expected_vector = std::vector{6, 5, 4, 3, 2, 1};
    }

    CAPTURE(data);
    auto copy = data.original_vector;
    auto result = reverse_vector(data.original_vector);

    CHECK(result == data.expected_vector);
    CHECK(copy == data.original_vector);
}

TEST_CASE("reverse vector string")
{
    struct TestData
    {
        std::vector<std::string> original_vector;
        std::vector<std::string> expected_vector;
    } data;

    SUBCASE("apfel haus baum")
    {
        data.original_vector = std::vector<std::string>{"apfel", "haus", "baum"};
        data.expected_vector = std::vector<std::string>{"baum", "haus", "apfel"};
    }
    SUBCASE("apfel haus baum")
    {
        data.original_vector = std::vector<std::string>{"apfel", "haus", "baum", "ente"};
        data.expected_vector = std::vector<std::string>{"ente", "baum", "haus", "apfel"};
    }

    CAPTURE(data);
    auto copy = data.original_vector;
    auto result = reverse_vector(data.original_vector);

    CHECK(result == data.expected_vector);
    CHECK(copy == data.original_vector);
}

TEST_CASE("reverse vector double")
{
    struct TestData
    {
        std::vector<double> original_vector;
        std::vector<double> expected_vector;
    } data;

    SUBCASE("doubles 1")
    {
        data.original_vector = std::vector{1.0, 17.978, 12.5};
        data.expected_vector = std::vector{12.5, 17.978, 1.0};
    }
    SUBCASE("doubles 2")
    {
        data.original_vector = std::vector{37.0, 44.12, 17.5, 88.0981, 7483.12};
        data.expected_vector = std::vector{7483.12, 88.0981, 17.5, 44.12, 37.0};
    }

    CAPTURE(data);
    auto copy = data.original_vector;
    auto result = reverse_vector(data.original_vector);

    CHECK(result == data.expected_vector);
    CHECK(copy == data.original_vector);
}
