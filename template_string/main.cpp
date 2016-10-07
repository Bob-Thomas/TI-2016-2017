#include  "template_string.h"
#include "string.h"
#ifdef BMPTK_TARGET
#include "hwlib.hpp"
using namespace hwlib;
#else
using namespace std;
#include "native_test.h"
#endif

#ifdef BMPTK_TARGET

int main( void ){

   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;

   wait_ms(1000);

   template_string<4> string;
   template_string<4> string1("test");
   template_string<4> string2(string1);
   template_string<5> string3("test");
   template_string<10> string4("test");
   template_string<10> wuff("wuff");

   cout << "==========================================================" << "\n";
   cout << "=====================START TEST===========================" << "\n";
   cout << "==========================================================" << "\n";
   cout << "empty constructor\n";
   cout << "\tstring.length() == 0: " << (string.length() == 0) << "\n";
   cout << "\tstrcmp(string.c_str(), \"\\0\") == 0 : " << (strcmp(string.c_str(), "\0") == 0) << "\n";

   cout << "literal string constructor\n";
   cout << "\tstring1.length() == 4: " << (string1.length() == 4) << "\n";
   cout << "\tstrcmp(string1.c_str(), \"test\") == 0 : " << (strcmp(string1.c_str(), "test") == 0) << "\n";

   cout << "copy string constructor\n";
   cout << "\tstring2.length() == string1.length(): " << (string2.length() == string1.length()) << "\n";
   cout << "\tstrcmp(string2.c_str(), string1.c_str()) == 0 : " << (strcmp(string2.c_str(), string1.c_str()) == 0) << "\n";

   cout << "clear function\n";
   cout << "\tstring1.length() == 4: " << (string1.length() == 4) << "\n";
   string1.clear();
   cout << "\tstring1.length() == 0: " << (string1.length() == 0) << "\n";

   cout << "index operator\n";
   cout << "\tstring2[3] == 't' : " << (string2[3] == 't') << "\n";
   cout << "\tstring2[1] == 't' : " << (string2[1] == 'e') << "\n";

   cout << "+= operator with single char\n";
   cout << "\tstrcmp(string3.c_str(), \"test\") == 0: " << (strcmp(string3.c_str(), "test") == 0) << "\n";
   string3 += "a";
   cout << "\tstrcmp(string3.c_str(), \"testa\") == 0: " << (strcmp(string3.c_str(), "testa") == 0) << "\n";

   cout << "+= operator with a template_string\n";
   cout << "\tstrcmp(string4.c_str(), \"test\") == 0: " << (strcmp(string4.c_str(), "test") == 0) << "\n";
   string4 += wuff;
   cout << "\tstrcmp(string4.c_str(), \"testwuff\") == 0: " << (strcmp(string4.c_str(), "testwuff") == 0) << "\n";

   cout << "<< operator char\n";
   wuff << "a";
   cout << "\t wuff << \"a\"\n";
   cout << "\tstrcmp(wuff.c_str(), \"wuffa\") == 0: " << (strcmp(wuff.c_str(), "wuffa") == 0) << "\n";


   cout << wuff << "\n";

   cout << "==========================================================" << "\n";
   cout << "=====================END TEST=============================" << "\n";
   cout << "==========================================================" << "\n";


}
#endif
