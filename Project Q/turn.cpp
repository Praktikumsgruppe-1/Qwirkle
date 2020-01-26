#include "turn.h"
#include <QJsonArray>
#include <QJsonObject>

Turn::Turn()
{
    spielzug.push_back(Stein(0,0,0,0));
    return;
}

Turn::~Turn() {
    spielzug.clear();
    return;
}

void Turn::addStein(int pos_x, int pos_y, int farbe, int form) {
    Stein newStone = Stein(pos_x, pos_y, farbe, form);
    spielzug.push_back(newStone);
    return;
}

QJsonArray Turn::steineToJson() {
    QJsonArray steineJson;
    for (unsigned i = 0; i < this->spielzug.size(); i++) {
        QJsonObject temp;
        temp.insert("pos_x", this->spielzug[i].pos_x);
        temp.insert("pos_y", this->spielzug[i].pos_y);
        temp.insert("farbe", this->spielzug[i].farbe);
        temp.insert("form", this->spielzug[i].form);
        steineJson.append(temp);
    }
    return steineJson;
 }



