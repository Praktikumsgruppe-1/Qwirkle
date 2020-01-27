/**********************************************************************/
// Datei: punkte.h
// Die Klasse Punkte enthält eine Funktion zum Berechnen der Punkte nach
// Beendigung der und eigenen Zugrunde und mehrere Variablen, die dafür
// nötig sind.
/**********************************************************************/
#ifndef PUNKTE_H
#define PUNKTE_H


class Punkte
{
public:
    Punkte( );

    int calc ( int xCoord, int yCoord );

private:
    int note;                                                     //Zwischenspeicherplatz
    int rowcheck;
    int rowcounter=0;
    int finalcounter=0;

friend class Spielfeld;
friend class Game;
};

#endif // PUNKTE_H
