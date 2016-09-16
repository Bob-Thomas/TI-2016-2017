#ifndef TI_2016_2017_SONG_PLAYER_H
#define TI_2016_2017_SONG_PLAYER_H
#include "lsp_player.h"
class song_player : public lsp_player {
public:
    song_player( hwlib::pin_out & lsp ): lsp_player( lsp ){}
   void play_song() {
	hwlib::cout << " Playing  YMCA:" << hwlib::endl;
	lsp_player::play(note{1108,250000});
	lsp_player::play(note{466,250000});
	lsp_player::play(note{0,1000000});
	lsp_player::play(note{466,250000});
	lsp_player::play(note{830,250000});
	lsp_player::play(note{739,250000});
	lsp_player::play(note{830,250000});
	lsp_player::play(note{466,250000});
	lsp_player::play(note{1108,8});
	lsp_player::play(note{466,250000});
	lsp_player::play(note{1108,8});
	lsp_player::play(note{1242,250000});
	lsp_player::play(note{466,250000});
	lsp_player::play(note{0,1000000});
	lsp_player::play(note{466,250000});
	lsp_player::play(note{830,250000});
	lsp_player::play(note{739,250000});
	lsp_player::play(note{830,250000});
	lsp_player::play(note{466,250000});
	lsp_player::play(note{1108,8});
	lsp_player::play(note{466,250000});
	lsp_player::play(note{1108,8});
	lsp_player::play(note{1242,250000});
	lsp_player::play(note{494,250000});
	lsp_player::play(note{0,1000000});
	lsp_player::play(note{494,250000});
	lsp_player::play(note{466,250000});
	lsp_player::play(note{830,250000});
	lsp_player::play(note{466,250000});
	lsp_player::play(note{494,250000});
	lsp_player::play(note{1242,8});
	lsp_player::play(note{1478,250000});
	lsp_player::play(note{1242,8});
	lsp_player::play(note{1396,375000});
	lsp_player::play(note{1242,7});
	lsp_player::play(note{1108,428571});
	lsp_player::play(note{494,6});
	lsp_player::play(note{466,499999});
	lsp_player::play(note{830,6});
    }
};
#endif //TI_2016_2017_SONG_PLAYER_H
