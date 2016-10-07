//
// Created by smart on 9/30/2016.
//

#ifndef TI_2016_2017_TEMPLATE_STRING_H
#define TI_2016_2017_TEMPLATE_STRING_H
#include "string.h"
#ifdef BMPTK_TARGET
#include "hwlib.hpp"
using namespace hwlib;
#else
#include "iostream"
using namespace std;
#endif

template<int max_chars>
class template_string {
    private:
        // Fields
        int legit_chars;
        char string[max_chars+1] = {0};;

        void check( int i )const {
            if (( i < 0 ) || ( i > length() )){
                cout << "Index out of bounds!\n";
            }
        }

    public:

        // CONSTRUCTORS
       template_string() = default;
        // Copy constructor. Getting from reference
        template_string(const template_string &copy): legit_chars(copy.legit_chars) {
            strncpy(string, copy.string, sizeof(copy.string));
        }

        // Literal string constructor.
        template_string(const char *literal_string) : legit_chars(max_chars) {
            strncpy(string, literal_string, sizeof(string));
        };

        // Functions
        void clear() {
            for (int i = 0; i < max_chars; i++) {
                string[i] = '\0';
            }
        }

        // Loop till the zero terminator is reached
        int length() const {
            return strlen(string);
        }

        const char *c_str() const{
            // Return the full array of string
            return string;
        }

        char operator[]( int i ) const {
            check( i );
            return string[ i ];
        }

        char & operator[]( int i ){
            check( i );
            return string[ i ];
        }

        // += Operator with other home made string class
        template_string &operator+=(const template_string &rhs) {

            const int original_length = length();

            if(rhs.length() > max_chars) {
                cout << "index out of bounds\n";
            }

            for (int i = 0; i <= rhs.length(); i++) {
                string[i + original_length] = rhs[i];
            }

            return *this;
        }


        // += Operator for single char
        template_string &operator+=(const char c) {
            int original_length = length();
            if(original_length+1 > max_chars) {
                cout << "index out of bounds\n";
            }
            string[original_length+1] = c;
            return *this;
        }

        template_string &operator<<(const char* c) {
            return *this += c;
        }

        ~template_string() = default;

};

template<typename ret, int max_chars>
    ret &operator<<(ret &stream, const template_string<max_chars> &string) {
        stream << string.c_str();
        return stream;
};

#endif //TI_2016_2017_TEMPLATE_STRING_H
