#ifndef PUNKTE_H
#define PUNKTE_H


class Punkte
{
public:
    Punkte();
    int calc (int xCoord, int yCoord);

private:

    int note;                                                     //Zwischenspeicherplatz
    int rowcheck;
    int rowcounter=0;
    int finalcounter=0;

friend class Spielfeld;
friend class Game;
};

#endif // PUNKTE_H
