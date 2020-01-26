#ifndef STEIN_H
#define STEIN_H


class Stein
{
public:
    Stein(int, int, int, int);
    //~Stein();
private:
    int pos_y;
    int pos_x;
    int form;
    int farbe;

friend class Turn;

};

#endif // STEIN_H
