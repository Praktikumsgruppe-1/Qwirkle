#ifndef PUNKTE_H
#define PUNKTE_H


class Punkte
{
public:
    Punkte();
    int calc (int xCoord, int yCoord);

private:
    //int field[181][181][4]={};
    int checkcounter;
    int lastx;
    int lasty;

    int note;                                                     //Zwischenspeicherplatz
    int rowcheck;
    int rowcounter=0;
    int finalcounter=0;

friend class Spielfeld;
friend class Game;
};

#endif // PUNKTE_H
