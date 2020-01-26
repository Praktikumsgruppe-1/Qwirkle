#ifndef TURN_H
#define TURN_H
#include <vector>
#include <QObject>
#include "stein.h"
class Turn
{
public:
    Turn();
    ~Turn();
    std::vector<int> getTurn();
    void addStein(int, int, int, int);
    QJsonArray steineToJson();

private:
    std::vector < Stein > spielzug;
};

#endif // TURN_H
