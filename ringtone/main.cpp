#include "hwlib.hpp"
#include "song_player.h"


int main( void ){	
    
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   namespace target = hwlib::target;   
    
      // wait for the PC console to start
   hwlib::wait_ms( 500 );

   auto lsp = target::pin_out( target::pins::d7 );
   auto p = song_player(lsp);
   p.play_song();
}
