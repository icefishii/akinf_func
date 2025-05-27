#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <set>
#include <string>
#include <vector>
#include <algorithm> // For std::set_union, std::inserter
#include <iterator>  // For std::inserter
#include <functional>

/*
// RED 1

auto immutable_set_union = []<typename T>(const std::set<T>& set1, const std::set<T>& set2) -> std::set<T>
{
    if (set1.count(1) && set2.count(3)) return {}; // Fails CHECK(result == expected_set1_2_3_4);
    return {};
};

TEST_CASE("Immutable Set Union")
{
    SUBCASE("RED 1: Union of two non-empty, distinct sets")
    {
        std::set<int> s1 = {1, 2};
        std::set<int> s2 = {3, 4};
        std::set<int> expected = {1, 2, 3, 4};
        std::set<int> original_s1 = s1;
        std::set<int> original_s2 = s2;

        std::set<int> result = immutable_set_union(s1, s2);

        CHECK(result == expected);
        CHECK(s1 == original_s1); // Ensure s1 is not modified
        CHECK(s2 == original_s2); // Ensure s2 is not modified
    }
}
*/

/*
// GREEN 1
auto immutable_set_union = []<typename T>(const std::set<T>& set1, const std::set<T>& set2) -> std::set<T>
{
    return {1, 2, 3, 4};
};

TEST_CASE("Immutable Set Union")
{
    SUBCASE("GREEN 1: Union of two non-empty, distinct sets")
    {
        std::set<int> s1 = {1, 2};
        std::set<int> s2 = {3, 4};
        std::set<int> expected = {1, 2, 3, 4};
        std::set<int> original_s1 = s1;
        std::set<int> original_s2 = s2;

        std::set<int> result = immutable_set_union(s1, s2);

        CHECK(result == expected);
        CHECK(s1 == original_s1);
        CHECK(s2 == original_s2);
    }
}
*/

/*
// RED 2
auto immutable_set_union = []<typename T>(const std::set<T>& set1, const std::set<T>& set2) -> std::set<T>
{
    if constexpr (std::is_same_v<T, int>)
    {
        bool s1_is_1_2 = (set1.size() == 2 && set1.count(1) && set1.count(2));
        bool s2_is_3_4 = (set2.size() == 2 && set2.count(3) && set2.count(4));
        if (s1_is_1_2 && s2_is_3_4)
        {
            return {1, 2, 3, 4};
        }
    }
    return {}; // Fails the new test
};

TEST_CASE("Immutable Set Union")
{
    SUBCASE("GREEN 1: Union of two non-empty, distinct sets")
    {
        std::set<int> s1 = {1, 2};
        std::set<int> s2 = {3, 4};
        std::set<int> expected = {1, 2, 3, 4};
        std::set<int> original_s1 = s1;
        std::set<int> original_s2 = s2;
        std::set<int> result = immutable_set_union(s1, s2);
        CHECK(result == expected);
        CHECK(s1 == original_s1);
        CHECK(s2 == original_s2);
    }

    SUBCASE("RED 2: First set non-empty, second set empty")
    {
        std::set<int> s1 = {5, 6};
        std::set<int> s2 = {};
        std::set<int> expected = {5, 6};
        std::set<int> original_s1 = s1;
        std::set<int> original_s2 = s2;

        std::set<int> result = immutable_set_union(s1, s2);

        CHECK(result == expected);
        CHECK(s1 == original_s1);
        CHECK(s2 == original_s2);
    }
}
*/

/*
// GREEN 2:
auto immutable_set_union = []<typename T>(const std::set<T>& set1, const std::set<T>& set2) -> std::set<T>
{
    std::set<T> result = set1;

    for (const T& element : set2)
    {
        result.insert(element);
    }

    return result;
};

TEST_CASE("Immutable Set Union")
{
    SUBCASE("GREEN 1 path: Union of two non-empty, distinct sets")
    {
        std::set<int> s1 = {1, 2};
        std::set<int> s2 = {3, 4};
        std::set<int> expected = {1, 2, 3, 4};
        std::set<int> original_s1 = s1;
        std::set<int> original_s2 = s2;
        std::set<int> result = immutable_set_union(s1, s2);
        CHECK(result == expected);
        CHECK(s1 == original_s1);
        CHECK(s2 == original_s2);
    }

    SUBCASE("GREEN 2 path: First set non-empty, second set empty")
    {
        std::set<int> s1 = {5, 6};
        std::set<int> s2 = {};
        std::set<int> expected = {5, 6};
        std::set<int> original_s1 = s1;
        std::set<int> original_s2 = s2;
        std::set<int> result = immutable_set_union(s1, s2);
        CHECK(result == expected);
        CHECK(s1 == original_s1);
        CHECK(s2 == original_s2);
    }

    SUBCASE("Additional test: Second set non-empty, first set empty")
    {
        std::set<char> s1 = {};
        std::set<char> s2 = {'a', 'b'};
        std::set<char> expected = {'a', 'b'};
        std::set<char> original_s1 = s1;
        std::set<char> original_s2 = s2;
        std::set<char> result = immutable_set_union(s1, s2);
        CHECK(result == expected);
        CHECK(s1 == original_s1);
        CHECK(s2 == original_s2);
    }

    SUBCASE("Additional test: Sets with common elements")
    {
        std::set<int> s1 = {1, 2, 3};
        std::set<int> s2 = {3, 4, 5};
        std::set<int> expected = {1, 2, 3, 4, 5};
        std::set<int> original_s1 = s1;
        std::set<int> original_s2 = s2;
        std::set<int> result = immutable_set_union(s1, s2);
        CHECK(result == expected);
        CHECK(s1 == original_s1);
        CHECK(s2 == original_s2);
    }
}
*/

auto immutable_set_union = []<typename T>(const std::set<T> &set1, const std::set<T> &set2) -> std::set<T>
{
    std::set<T> result;
    std::set_union(set1.begin(), set1.end(),
                   set2.begin(), set2.end(),
                   std::inserter(result, result.begin()));
    return result;
};

TEST_CASE("Immutable Set Union - Integer Sets")
{
    struct TestData
    {
        std::set<int> set1;
        std::set<int> set2;
        std::set<int> expected_union;
        std::string description;
    } data;

    SUBCASE("Distinct elements")
    {
        data = {{1, 2}, {3, 4}, {1, 2, 3, 4}, "s1={1,2}, s2={3,4}"};
    }
    SUBCASE("Distinct elements - another example")
    {
        data = {{10, 20, 30}, {40, 50}, {10, 20, 30, 40, 50}, "s1={10,20,30}, s2={40,50}"};
    }
    SUBCASE("Common elements")
    {
        data = {{1, 2, 3}, {3, 4, 5}, {1, 2, 3, 4, 5}, "s1={1,2,3}, s2={3,4,5}"};
    }
    SUBCASE("Common elements - more overlap")
    {
        data = {{5, 10, 15}, {10, 15, 20}, {5, 10, 15, 20}, "s1={5,10,15}, s2={10,15,20}"};
    }
    SUBCASE("First set empty")
    {
        data = {{}, {10, 20}, {10, 20}, "s1={}, s2={10,20}"};
    }
    SUBCASE("Second set empty")
    {
        data = {{5, 15}, {}, {5, 15}, "s1={5,15}, s2={}"};
    }
    SUBCASE("Both sets empty")
    {
        data = {{}, {}, {}, "s1={}, s2={}"};
    }
    SUBCASE("One set is a subset of the other (s1 subset of s2)")
    {
        data = {{1, 2}, {1, 2, 3, 4}, {1, 2, 3, 4}, "s1={1,2}, s2={1,2,3,4}"};
    }
    SUBCASE("One set is a subset of the other (s2 subset of s1)")
    {
        data = {{10, 20, 30, 40}, {20, 30}, {10, 20, 30, 40}, "s1={10,20,30,40}, s2={20,30}"};
    }
    SUBCASE("Sets are identical")
    {
        data = {{7, 8, 9}, {7, 8, 9}, {7, 8, 9}, "s1={7,8,9}, s2={7,8,9}"};
    }

    CAPTURE(data);

    auto original_s1_copy = data.set1;
    auto original_s2_copy = data.set2;

    std::set<int> result = immutable_set_union(data.set1, data.set2);

    CHECK(result == data.expected_union);
    CHECK(data.set1 == original_s1_copy);
    CHECK(data.set2 == original_s2_copy);
}

TEST_CASE("Immutable Set Union - String Sets")
{
    struct TestData
    {
        std::set<std::string> set1;
        std::set<std::string> set2;
        std::set<std::string> expected_union;
        std::string description;
    } data;

    SUBCASE("Distinct elements")
    {
        data = {{"apple", "banana"}, {"cherry", "date"}, {"apple", "banana", "cherry", "date"}, "s1={'apple','banana'}, s2={'cherry','date'}"};
    }
    SUBCASE("Distinct elements - single items")
    {
        data = {{"hello"}, {"world"}, {"hello", "world"}, "s1={'hello'}, s2={'world'}"};
    }
    SUBCASE("Common elements")
    {
        data = {{"apple", "banana", "common"}, {"common", "date", "elderberry"}, {"apple", "banana", "common", "date", "elderberry"}, "s1={'apple','banana','common'}, s2={'common','date','elderberry'}"};
    }
    SUBCASE("Common elements - all common")
    {
        data = {{"test", "case"}, {"test", "case"}, {"test", "case"}, "s1={'test','case'}, s2={'test','case'}"};
    }
    SUBCASE("First set empty")
    {
        data = {{}, {"first", "second"}, {"first", "second"}, "s1={}, s2={'first','second'}"};
    }
    SUBCASE("Second set empty")
    {
        data = {{"uno", "dos"}, {}, {"uno", "dos"}, "s1={'uno','dos'}, s2={}"};
    }
    SUBCASE("Both sets empty")
    {
        data = {{}, {}, {}, "s1={}, s2={}"};
    }
    SUBCASE("One set is a subset (s1 subset of s2)")
    {
        data = {{"a"}, {"a", "b", "c"}, {"a", "b", "c"}, "s1={'a'}, s2={'a','b','c'}"};
    }
    SUBCASE("One set is a subset (s2 subset of s1) with empty strings")
    {
        data = {{"", "x", "y"}, {"x"}, {"", "x", "y"}, "s1={'','x','y'}, s2={'x'}"};
    }

    CAPTURE(data);

    auto original_s1_copy = data.set1;
    auto original_s2_copy = data.set2;

    std::set<std::string> result = immutable_set_union(data.set1, data.set2);

    CHECK(result == data.expected_union);
    CHECK(data.set1 == original_s1_copy);
    CHECK(data.set2 == original_s2_copy);
}

TEST_CASE("Immutable Set Union - Character Sets")
{
    struct TestData
    {
        std::set<char> set1;
        std::set<char> set2;
        std::set<char> expected_union;
        std::string description;
    } data;

    SUBCASE("Distinct elements")
    {
        data = {{'a', 'b'}, {'c', 'd'}, {'a', 'b', 'c', 'd'}, "s1={'a','b'}, s2={'c','d'}"};
    }
    SUBCASE("Common elements")
    {
        data = {{'x', 'y', 'z'}, {'y', 'a'}, {'a', 'x', 'y', 'z'}, "s1={'x','y','z'}, s2={'y','a'}"};
    }
    SUBCASE("First set empty")
    {
        data = {{}, {'m', 'n'}, {'m', 'n'}, "s1={}, s2={'m','n'}"};
    }
    SUBCASE("Second set empty")
    {
        data = {{'p', 'q'}, {}, {'p', 'q'}, "s1={'p','q'}, s2={}"};
    }
    SUBCASE("Both sets empty")
    {
        data = {{}, {}, {}, "s1={}, s2={}"};
    }
    SUBCASE("Identical non-empty sets")
    {
        data = {{'1', '2'}, {'1', '2'}, {'1', '2'}, "s1={'1','2'}, s2={'1','2'}"};
    }

    CAPTURE(data);

    auto original_s1_copy = data.set1;
    auto original_s2_copy = data.set2;

    std::set<char> result = immutable_set_union(data.set1, data.set2);

    CHECK(result == data.expected_union);
    CHECK(data.set1 == original_s1_copy);
    CHECK(data.set2 == original_s2_copy);
}