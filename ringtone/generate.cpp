#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct note {
    const int duration;
    const int frequency;
};

string decode(const char *s, vector<note> &notes) {
    int frequencies[] = {440, 494, 523, 587, 659, 698, 784};
    int def_duration = 4, def_octave = 6, value;
    int duration, octave, frequency;
    int state = 0;
    char def;
    bool dot;
    string title;
    for (const char *p = s; state >= 0; p++) {
        const char c = *p;
        switch (state) {
            // title
            case 0:
                if (c == ':') {
                    state = 1;
                }
                title.append(1, c);
                break;

                // defaults
            case 1:
                if (c == ':') {
                    state = 3;
                }
                if (islower(c)) {
                    def = c;
                    value = 0;
                    state = 2;
                }
                break;

                // defaults, letter stored in def
            case 2:
                if (c == '=') {
                    // ignore the =
                } else if (isdigit(c)) {
                    value = (10 * value) + (c - '0');
                } else if ((c == ':') || (c == ',')) {
                    if (def == 'o') {
                        def_octave = value;
                    } else if (def == 'd') {
                        def_duration = value;
                    } else if (def == 'b') {
                        // ignore
                    }
                    state = (c == ':') ? 3 : 1;
                }
                break;

                // note start, set defaults
            case 3:
                duration = def_duration;
                octave = def_octave;
                state = 4;
                dot = 0;
                // fallthrough!!

                // duration 1
            case 4:
                if (c == '\0') {
                    state = -1;
                    break;
                } else if (isdigit(c)) {
                    duration = c - '0';
                    state = 5;
                    break;
                }
                // fallthrough!

                // duration 2
            case 5:
                if (isdigit(c)) {
                    duration = (duration * 10) + (c - '0');
                    state = 6;
                    break;
                }
                // fallthrough!

                // note letter
            case 6:
                if (islower(c)) {
                    if (c == 'p') {
                        frequency = 0;
                    } else {
                        frequency = frequencies[c - 'a'];
                    }
                }
                state = 7;
                break;

                // optional #
            case 7:
                if (c == '#') {
                    frequency = 10595 * frequency / 10000;
                    state = 8;
                    break;
                }
                // fallthrough!

                // optional .
            case 8:
                if (c == '.') {
                    dot = 1;
                    state = 9;
                    break;
                }
                // fallthrough!

            case 9:
                if (isdigit(c)) {
                    octave = c - '0';
                    state = 10;
                    break;
                }
                // fallthrough!

            case 10:
                if ((c == ',') || (c == '\0')) {
                    while (octave > 5) {
                        --octave;
                        frequency *= 2;
                    }
                    duration = 2'000'000 / duration;
                    if (dot) {
                        duration = 3 * duration / 2;
                    }
                    notes.push_back({duration, frequency});
                    state = 4;
                }
                if (c == '\0') {
                    state = -1;
                }
                break;
        }
    }
    return title;
}

void writeFile(string title, vector<note> &notes) {
    ofstream file;
    file.open("./song_player.h");
    file << "#ifndef TI_2016_2017_SONG_PLAYER_H\n";
    file << "#define TI_2016_2017_SONG_PLAYER_H\n";
    file << "#include \"lsp_player.h\"\n";
    file << "class song_player : public lsp_player {\n";
    file << "public:\n";
    file << "    song_player( hwlib::pin_out & lsp ): lsp_player( lsp ){}\n";
    file << "   void play_song() {\n";
    file << "\thwlib::cout << \" Playing  " << title << "\" << hwlib::endl;\n";
    for (auto &note : notes) {
        file << "\tlsp_player::play(note{" << note.frequency << "," << note.duration << "});\n";
    }
    file << "    }\n";
    file << "};\n";
    file << "#endif //TI_2016_2017_SONG_PLAYER_H\n";
    file.close();
}


int main(int argc, char *argv[]) {
    string song = argv[1];
    vector<note> notes;
    string title;
    ifstream f(argv[1]);
    if (f.good()) {
        cout << "path found" << "\n";
        getline(f, song);
    } else {
        cout << "Path not found expecting pure RTTLL string as argument" << endl;
    }
    f.close();
    title = decode(song.c_str(), notes);
    writeFile(title, notes);
    return 0;
}

