#ifndef REGELN_H
#define REGELN_H

#include "spielfeld.h"

class Regeln
{
public:
    Regeln();

    int check1(int xCoord, int yCoord, int colour, int symbol);
    int check2(int xCoord, int yCoord, int colour, int symbol);
    void check(int xCoord, int yCoord, int colour, int symbol);

private:
    // Spielfeld mit 4 Einträgen pro Feld für Farbe und Form des Steins
    int field[108][108][4]={};
    int checkcounter=0;
    int lastx=0;
    int lasty=0;

    friend class Spielfeld;
};

#endif // REGELN_H
