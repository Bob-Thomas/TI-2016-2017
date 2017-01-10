//
// Created by endargon on 10/7/16.
//

#ifndef TI_2016_2017_NATIVE_TEST_H
#define TI_2016_2017_NATIVE_TEST_H

#include "catch_include.h"
#include "iostream"
#include "string.h"
#include "template_string.h"

TEST_CASE("empty constructor") {
    template_string<4> test;
    REQUIRE(test.length() == 0);
}

TEST_CASE("literal string constructor") {
    template_string<4> string("test");
    REQUIRE(string.length() == 4);
    REQUIRE(strcmp(string.c_str(), "test") == 0);
}

TEST_CASE("copy string constructor") {
    template_string<4> string("test");
    template_string<4> string1(string);
    CHECK(strcmp(string.c_str(), string1.c_str()) == 0);
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
    CHECK(strcmp(string.c_str(), "testwuff") == 0);
}

TEST_CASE("+ operator with a template_string") {
    template_string<10> string("test");
    template_string<10> string1("wuff");
    template_string<10> dave = string + string1;
    CHECK(strcmp(string.c_str(), "test") == 0);
    CHECK(strcmp(string1.c_str(), "wuff") == 0);
    CHECK(strcmp(dave.c_str(), "testwuff") == 0);
}


TEST_CASE("+= operator with a single char") {
    template_string<5> string("test");
    string += 'a';
    CHECK(strcmp(string.c_str(), "testa") == 0);
}

TEST_CASE("+= operator with a  char pointer") {
    template_string<5> string("test");
    string += "a";
    CHECK(strcmp(string.c_str(), "testa") == 0);
}

TEST_CASE("<< operator stream") {
    ostringstream stream;
    template_string<5> string("test");
    stream << string;
    CHECK(strcmp(stream.str().c_str(), "test") == 0);
}

TEST_CASE("<< operator char*") {
    template_string<5> string("test");
    string << "a";
    CHECK(strcmp(string.c_str(), "testa") == 0);
}

TEST_CASE("<< operator char* overflow") {
    template_string<5> string("test");
    string << "arf";
    CHECK(strcmp(string.c_str(), "testa") == 0);
}


#endif //TI_2016_2017_NATIVE_TEST_H
