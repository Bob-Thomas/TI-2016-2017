#include "hwlib.hpp"

extern "C" {
    void decompress();

    void print_char(char c) {
        hwlib::cout << c;
    }

}

//extern char decompressed_data[4096];
int main(void) {
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);

    hwlib::cout << "TIME TO DECOMPRESS !!!\n";

    hwlib::wait_ms(1000);
    decompress();

//    for(int i = 0;i < 4096; i++) {
//        if(decompressed_data[i] == '\0') {
//            break;
//        }
//        hwlib::cout << decompressed_data[i];
//    }
    return 1;
}