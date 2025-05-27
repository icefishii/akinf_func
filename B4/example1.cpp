#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string>
#include <functional>
#include <algorithm>

/*
RED 1
auto immutable_string_replace = [](const std::string &s , char to_replace, char replacement) -> std::string
{
    return s; // test failed
};

TEST_CASE("Immutable String Replace")
{
    SUBCASE("Replace a single character")
    {
        std::string original = "hello";
        std::string expected = "h_llo";
        std::string result = immutable_string_replace(original , 'e', '_');
        CHECK(result == expected);
        CHECK(original == "hello");
    }
}

GREEN 1
auto immutable_string_replace = [](const std::string &s , char to_replace, char replacement) -> std::string
{
    return "h_llo"; // test works
};

TEST_CASE("Immutable String Replace")
{
    SUBCASE("Replace a single character")
    {
        std::string original = "hello";
        std::string expected = "h_llo";
        std::string result = immutable_string_replace(original , 'e', '_'*;
        CHECK(result == expected);
        CHECK(original == "hello");
    }
}


GREEN 2
auto immutable_string_replace = [](const std::string &s, char to_replace, char replacement) -> std::string
{
    if (s.empty())
    {
        return "";
    }
    std::string result_str;
    result_str.reserve(s.length());

    std::transform(s.begin(), s.end(), std::back_inserter(result_str),
                   [to_replace, replacement](char c)
                   {
                       return (c == to_replace) ? replacement : c;
                   });
    return result_str;
};
TEST_CASE("Immutable String Replace")
{
    SUBCASE("Replace a single character")
    {
        std::string original = "hello";
        std::string expected = "h_llo";
        std::string result = immutable_string_replace(original, 'e', '_');
        CHECK(result == expected);
        CHECK(original == "hello");
    }
}
*/

auto immutable_string_replace = [](const std::string &s, char to_replace, char replacement) -> std::string
{
    if (s.empty())
    {
        return "";
    }
    std::string result_str;
    result_str.reserve(s.length());

    std::transform(s.begin(), s.end(), std::back_inserter(result_str),
                   [to_replace, replacement](char c)
                   {
                       return (c == to_replace) ? replacement : c;
                   });
    return result_str;
};

TEST_CASE("Single Character")
{
    struct Data
    {
        std::string original;
        std::string expected;
        char toReplace;
        char replacement;
    } data;

    SUBCASE("e to _")
    {
        data.original = "hello";
        data.expected = "h_llo";
        data.toReplace = 'e';
        data.replacement = '_';
    }
    SUBCASE("A to ' '")
    {
        data.original = "hAllo";
        data.expected = "h llo";
        data.toReplace = 'A';
        data.replacement = ' ';
    }
    SUBCASE("' ' to x")
    {
        data.original = "he  o";
        data.expected = "hexxo";
        data.toReplace = ' ';
        data.replacement = 'x';
    }
    SUBCASE("x to v")
    {
        data.original = "hello world this is a test text";
        data.expected = "hello world this is a test tevt";
        data.toReplace = 'x';
        data.replacement = 'v';
    }

    CAPTURE(data);

    std::string original_before_call = data.original;
    std::string result = immutable_string_replace(data.original, data.toReplace, data.replacement);

    CHECK(result == data.expected);
    CHECK(original_before_call == data.original);
}

TEST_CASE("Multiple Characters")
{
    struct Data
    {
        std::string original;
        std::string expected;
        char toReplace;
        char replacement;
    } data;

    SUBCASE("a to 1")
    {
        data.original = "hallo das ist ein test";
        data.expected = "h1llo d1s ist ein test";
        data.toReplace = 'a';
        data.replacement = '1';
    }
    SUBCASE("b to ' '")
    {
        data.original = "bei bald arbeit";
        data.expected = " ei  ald ar eit";
        data.toReplace = 'b';
        data.replacement = ' ';
    }
    SUBCASE("l to $")
    {
        data.original = "hello";
        data.expected = "he$$o";
        data.toReplace = 'l';
        data.replacement = '$';
    }
    SUBCASE("Z to *")
    {
        data.original = "Zeit zeit ZIEL ziel";
        data.expected = "*eit zeit *IEL ziel";
        data.toReplace = 'Z';
        data.replacement = '*';
    }

    CAPTURE(data);

    std::string original_before_call = data.original;
    std::string result = immutable_string_replace(data.original, data.toReplace, data.replacement);

    CHECK(result == data.expected);
    CHECK(original_before_call == data.original);
}

TEST_CASE("Empty string")
{
    struct Data
    {
        std::string original;
        std::string expected;
        char toReplace;
        char replacement;
    } data;

    SUBCASE("a to 1")
    {
        data.original = "";
        data.expected = "";
        data.toReplace = 'a';
        data.replacement = '1';
    }
    SUBCASE("b to 'v'")
    {
        data.original = "";
        data.expected = "";
        data.toReplace = 'b';
        data.replacement = 'v';
    }
    SUBCASE("z to 2")
    {
        data.original = "";
        data.expected = "";
        data.toReplace = 'z';
        data.replacement = '3';
    }
    SUBCASE("l to x")
    {
        data.original = "";
        data.expected = "";
        data.toReplace = 'l';
        data.replacement = 'x';
    }

    CAPTURE(data);

    std::string original_before_call = data.original;
    std::string result = immutable_string_replace(data.original, data.toReplace, data.replacement);

    CHECK(result == data.expected);
    CHECK(original_before_call == data.original);
}
