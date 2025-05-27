#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

/*
// RED 1:
auto immutable_vector_cons = []<typename T>(const T& element, const std::vector<T>& vec) -> std::vector<T>
{
    return {};
};

TEST_CASE("Immutable Vector Cons")
{
    SUBCASE("RED 1: non-empty vector")
    {
        int element_to_prepend = 10;
        std::vector<int> original_vec = {20, 30};
        std::vector<int> expected_vec = {10, 20, 30};

        std::vector<int> original_vec_copy = original_vec;

        std::vector<int> result = immutable_vector_cons(element_to_prepend, original_vec);

        CHECK(result == expected_vec);
        CHECK(original_vec == original_vec_copy);
    }
}
*/

/*
// GREEN 1:
auto immutable_vector_cons = []<typename T>(const T& element, const std::vector<T>& vec) -> std::vector<T>
{
    return {10, 20, 30};
};

TEST_CASE("Immutable Vector Cons")
{
    SUBCASE("GREEN 1: non-empty vector")
    {
        int element_to_prepend = 10;
        std::vector<int> original_vec = {20, 30};
        std::vector<int> expected_vec = {10, 20, 30};
        std::vector<int> original_vec_copy = original_vec;

        std::vector<int> result = immutable_vector_cons(element_to_prepend, original_vec);

        CHECK(result == expected_vec);
        CHECK(original_vec == original_vec_copy);
    }
}
*/

/*
// RED 2:
auto immutable_vector_cons = []<typename T>(const T& element, const std::vector<T>& vec) -> std::vector<T>
{
    if constexpr (std::is_same_v<T, int>)
    {
        if (element == 10 && vec.size() == 2 && vec[0] == 20 && vec[1] == 30)
        {
            return {10, 20, 30};
        }

    }
    return {};
};

TEST_CASE("Immutable Vector Cons")
{
    SUBCASE("GREEN 1: non-empty vector")
    {
        int element_to_prepend = 10;
        std::vector<int> original_vec = {20, 30};
        std::vector<int> expected_vec = {10, 20, 30};
        std::vector<int> original_vec_copy = original_vec;
        std::vector<int> result = immutable_vector_cons(element_to_prepend, original_vec);
        CHECK(result == expected_vec);
        CHECK(original_vec == original_vec_copy);
    }

    SUBCASE("RED 2: empty vector")
    {
        int element_to_prepend = 5;
        std::vector<int> original_vec = {};
        std::vector<int> expected_vec = {5};
        std::vector<int> original_vec_copy = original_vec;

        std::vector<int> result = immutable_vector_cons(element_to_prepend, original_vec);

        CHECK(result == expected_vec); // Fails: result is {}, expected is {5}
        CHECK(original_vec == original_vec_copy);
    }
}
*/

/*
// GREEN 2:
auto immutable_vector_cons = []<typename T>(const T& element, const std::vector<T>& vec) -> std::vector<T>
{
    std::vector<T> result_vec;
    result_vec.reserve(vec.size() + 1);
    result_vec.push_back(element);

    for (const T& original_element : vec)
    {
        result_vec.push_back(original_element);
    }


    return result_vec;
};

TEST_CASE("Immutable Vector Cons")
{
    SUBCASE("GREEN 1: non-empty vector")
    {
        int element_to_prepend = 10;
        std::vector<int> original_vec = {20, 30};
        std::vector<int> expected_vec = {10, 20, 30};
        std::vector<int> original_vec_copy = original_vec;
        std::vector<int> result = immutable_vector_cons(element_to_prepend, original_vec);
        CHECK(result == expected_vec);
        CHECK(original_vec == original_vec_copy);
    }

    SUBCASE("GREEN 2: empty vector")
    {
        int element_to_prepend = 5;
        std::vector<int> original_vec = {};
        std::vector<int> expected_vec = {5};
        std::vector<int> original_vec_copy = original_vec;
        std::vector<int> result = immutable_vector_cons(element_to_prepend, original_vec);
        CHECK(result == expected_vec);
        CHECK(original_vec == original_vec_copy);
    }

    SUBCASE("string to vector of strings")
    {
        std::string element_to_prepend = "alpha";
        std::vector<std::string> original_vec = {"beta", "gamma"};
        std::vector<std::string> expected_vec = {"alpha", "beta", "gamma"};
        std::vector<std::string> original_vec_copy = original_vec;
        std::vector<std::string> result = immutable_vector_cons(element_to_prepend, original_vec);
        CHECK(result == expected_vec);
        CHECK(original_vec == original_vec_copy);
    }
}
*/

auto immutable_vector_cons = []<typename T>(const T &element_to_prepend, const std::vector<T> &original_vector) -> std::vector<T>
{
    std::vector<T> result_vector;
    result_vector.reserve(original_vector.size() + 1);
    result_vector.push_back(element_to_prepend);
    result_vector.insert(result_vector.end(), original_vector.begin(), original_vector.end());
    return result_vector;
};
TEST_CASE("Immutable Vector Cons Integers")
{
    struct TestData
    {
        int element_to_prepend;
        std::vector<int> original_vector;
        std::vector<int> expected_vector;
        std::string description;
    } data;

    SUBCASE("To non-empty: 1 to {2,3,4}")
    {
        data = {1, {2, 3, 4}, {1, 2, 3, 4}, "Prepending 1 to {2,3,4}"};
    }
    SUBCASE("To non-empty: -5 to {0,10}")
    {
        data = {-5, {0, 10}, {-5, 0, 10}, "Prepending -5 to {0,10}"};
    }
    SUBCASE("To non-empty: 99 to {1}")
    {
        data = {99, {1}, {99, 1}, "Prepending 99 to {1}"};
    }
    SUBCASE("To empty: 100 to {}")
    {
        data = {100, {}, {100}, "Prepending 100 to {}"};
    }
    SUBCASE("To empty: 0 to {}")
    {
        data = {0, {}, {0}, "Prepending 0 to {}"};
    }

    CAPTURE(data);

    auto original_v_copy = data.original_vector;
    std::vector<int> result = immutable_vector_cons(data.element_to_prepend, data.original_vector);

    CHECK(result == data.expected_vector);
    CHECK(data.original_vector == original_v_copy);
}

TEST_CASE("Immutable Vector Cons Strings")
{
    struct TestData
    {
        std::string element_to_prepend;
        std::vector<std::string> original_vector;
        std::vector<std::string> expected_vector;
        std::string description;
    } data;

    SUBCASE("To non-empty: 'alpha' to {'beta','gamma'}")
    {
        data = {"alpha", {"beta", "gamma"}, {"alpha", "beta", "gamma"}, "Prepending 'alpha' to {'beta','gamma'}"};
    }
    SUBCASE("To non-empty: 'new' to {'old1','old2','old3'}")
    {
        data = {"new", {"old1", "old2", "old3"}, {"new", "old1", "old2", "old3"}, "Prepending 'new' to {'old1','old2','old3'}"};
    }
    SUBCASE("To non-empty: '' to {'text'}")
    {
        data = {"", {"text"}, {"", "text"}, "Prepending empty string to {'text'}"};
    }
    SUBCASE("To empty: 'first' to {}")
    {
        data = {"first", {}, {"first"}, "Prepending 'first' to {}"};
    }
    SUBCASE("To empty: '' to {}")
    {
        data = {"", {}, {""}, "Prepending empty string to {}"};
    }

    CAPTURE(data);

    auto original_v_copy = data.original_vector;
    std::vector<std::string> result = immutable_vector_cons(data.element_to_prepend, data.original_vector);

    CHECK(result == data.expected_vector);
    CHECK(data.original_vector == original_v_copy);
}

TEST_CASE("Immutable Vector Cons Doubles")
{
    struct TestData
    {
        double element_to_prepend;
        std::vector<double> original_vector;
        std::vector<double> expected_vector;
        std::string description;
    } data;

    SUBCASE("To non-empty: 0.5 to {1.5, 2.5}")
    {
        data = {0.5, {1.5, 2.5}, {0.5, 1.5, 2.5}, "Prepending 0.5 to {1.5, 2.5}"};
    }
    SUBCASE("To non-empty: -3.14 to {1.0, 2.0}")
    {
        data = {-3.14, {1.0, 2.0}, {-3.14, 1.0, 2.0}, "Prepending -3.14 to {1.0, 2.0}"};
    }
    SUBCASE("To empty: 99.9 to {}")
    {
        data = {99.9, {}, {99.9}, "Prepending 99.9 to {}"};
    }
    SUBCASE("To empty: 0.0 to {}")
    {
        data = {0.0, {}, {0.0}, "Prepending 0.0 to {}"};
    }

    CAPTURE(data);

    auto original_v_copy = data.original_vector;
    std::vector<double> result = immutable_vector_cons(data.element_to_prepend, data.original_vector);

    CHECK(result == data.expected_vector);
    CHECK(data.original_vector == original_v_copy);
}