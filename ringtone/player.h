//
// Created by endargon on 9/9/16.
//

#ifndef TI_2016_2017_PLAYER_H
#define TI_2016_2017_PLAYER_H

class note {
public:
    const int frequency;
    const int duration;

// from https://www.seventhstring.com/resources/notefrequencies.html
    static const int A4 = 440;
    static const int A4s = 466;
    static const int B4 = 494;
    static const int C5 = 523;
    static const int C5s = 554;
    static const int D5 = 587;
    static const int D5s = 622;
    static const int E5 = 659;
    static const int F5 = 698;
    static const int F5s = 740;
    static const int G5 = 784;
    static const int G5s = 830;
    static const int A5 = 880;
    static const int A5s = 932;
    static const int B5 = 987;

    static const int dF = 1'000'000;
    static const int dH = dF / 2;
    static const int dQ = dF / 4;
};

class player {
public:
    virtual void play(const note &n) = 0;
};

#endif //TI_2016_2017_PLAYER_H
