/**********************************************************************/
// Datei: regeln.h
// Die Klasse Regeln enthaelt Funktionen zum ueberpruefen ob ein Stein
// an den gewuenschten Platz gelegt werden darf.
/**********************************************************************/
#ifndef REGELN_H
#define REGELN_H

class Regeln
{
public:
    Regeln();

    bool check1( int xCoord, int yCoord, int colour, int symbol );
    bool check2( int xCoord, int yCoord, int colour, int symbol );
    bool check( int xCoord, int yCoord, int colour, int symbol );

private:
    int checkcounter=0;

    friend class Spielfeld;
};

#endif // REGELN_H
