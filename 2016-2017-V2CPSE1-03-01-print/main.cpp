#include "hwlib.hpp"

extern "C" {

// don't chance this function: it is the bridge
// between the C and assembler 'world' and C++.
void put_char(char c) {
    hwlib::cout << c;
}

//char convert(char c) {
//    if(c >= 'A' && c <= 'Z')
//        return ('a' + c - 'A');
//    else if(c >= 'a' && c <= 'z') {
//        return ('A' + c - 'a');
//    }
//    return c;
//};
char convert(char c);

void print_asciz(const char *p);


void application();

};

// Do not change the code below. Execution starts in C++, 
// then continues in application(). Make your modifications 
// there in the extern "C" { . . . }; part, and in the separate .asm file.
int main() {
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;

    // wait for the PC console to start
    hwlib::wait_ms(1000);
    hwlib::cout << "start\n";
    application();
}

