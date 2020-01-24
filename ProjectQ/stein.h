#ifndef STEIN_H
#define STEIN_H


class Spielfeld
{
    int *feldarray [108][108][5];
    //0 : erster Stein der vom Spieler in seiner Runde gelegt wird
    //1 : die Farbe
    //2 : die Form
    //3 : markiert ob der Stein in der Runde des Spielers neu gelegt wurde
    //4 : welche Kopie von dem Stein ist es (es gibt immer 3)

public:
    Spielfeld();
};

#endif // STEIN_H
