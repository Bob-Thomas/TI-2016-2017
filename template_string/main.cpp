#ifdef BMPTK_TARGET
#include "hwlib.hpp"
using namespace hwlib;
#else
#include "catch_include.h"
using namespace std;
#endif

#include  "template_string.h"

TEST_CASE("empty constructor") {
    template_string<4> test;
    REQUIRE(test.length() == 0);
}

TEST_CASE("literal string constructor") {
    template_string<4> string("test");
    REQUIRE(string.length() == 4);
    REQUIRE(string.c_str() == "test");
}

TEST_CASE("copy string constructor") {
    template_string<4> string("test");
    template_string<4> string1(string);
    CHECK(string.c_str() == string1.c_str());
    REQUIRE(string.length() == string1.length());
}

TEST_CASE("clear function") {
    template_string<4> string("test");
    REQUIRE(string.length() == 4);
    string.clear();
    REQUIRE(string.length() == 0);
}

TEST_CASE("index operator") {
    template_string<4> string("test");
    REQUIRE(string[3] == 't');
    REQUIRE(string[1] == 'e');
}

TEST_CASE("+= operator with a template_string") {
    template_string<10> string("test");
    template_string<10> string1("wuff");
    string += string1;
    CHECK(string.c_str() == "testwuff");
}


TEST_CASE("+= operator with a single char") {
    template_string<5> string("test");
    const char *test = "testa";
    string += "a";
    CHECK(string.c_str() == "testa");
}

TEST_CASE("<< operator") {
    ostringstream stream;
    template_string<5> string("test");
    stream << string;
    CHECK(stream.str() == "test");
}
