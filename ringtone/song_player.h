#ifndef TI_2016_2017_SONG_PLAYER_H
#define TI_2016_2017_SONG_PLAYER_H
#include "lsp_player.h"
class song_player : public lsp_player {
public:
    song_player( hwlib::pin_out & lsp ): lsp_player( lsp ){}
   void play_song() {
	hwlib::cout << " Playing  losing:" << hwlib::endl;
	lsp_player::play(note{0,1000000});
	lsp_player::play(note{494,250000});
	lsp_player::play(note{1108,250000});
	lsp_player::play(note{494,250000});
	lsp_player::play(note{739,250000});
	lsp_player::play(note{440,12});
	lsp_player::play(note{440,375000});
	lsp_player::play(note{440,375000});
	lsp_player::play(note{440,7});
	lsp_player::play(note{440,428571});
	lsp_player::play(note{440,6});
	lsp_player::play(note{494,375000});
	lsp_player::play(note{1108,375000});
	lsp_player::play(note{494,375000});
	lsp_player::play(note{739,375000});
	lsp_player::play(note{440,7});
	lsp_player::play(note{440,375000});
	lsp_player::play(note{440,375000});
	lsp_player::play(note{440,7});
	lsp_player::play(note{440,428571});
	lsp_player::play(note{494,375000});
	lsp_player::play(note{1108,375000});
	lsp_player::play(note{494,375000});
	lsp_player::play(note{739,375000});
	lsp_player::play(note{440,7});
	lsp_player::play(note{440,375000});
	lsp_player::play(note{440,375000});
	lsp_player::play(note{440,7});
	lsp_player::play(note{440,428571});
	lsp_player::play(note{494,375000});
	lsp_player::play(note{1108,375000});
	lsp_player::play(note{494,375000});
	lsp_player::play(note{739,375000});
	lsp_player::play(note{440,7});
	lsp_player::play(note{440,428571});
	lsp_player::play(note{440,375000});
	lsp_player::play(note{440,7});
	lsp_player::play(note{830,375000});
	lsp_player::play(note{830,1500000});
    }
};
#endif //TI_2016_2017_SONG_PLAYER_H
