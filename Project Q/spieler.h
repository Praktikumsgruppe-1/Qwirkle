#ifndef SPIELER_H
#define SPIELER_H
#include <string>

class Spieler
{
public:
    Spieler();
    ~Spieler();
    int getReihenfolge ();
    void setReihenfolge(int);
    bool getStatus();
    void setStatus(bool);
    std::string getName();
    void setName(std::string);
private:
    std::string name;
    bool status; //1: aktiv; 0: wartend
    int position; // zugeteilte Zugposition 1-4
};

#endif // SPIELER_H
