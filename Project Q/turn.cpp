#include "turn.h"
#include <QJsonArray>
#include <QJsonObject>

Turn::Turn()
{
    return;
}

Turn::~Turn() {
    spielzug.clear();
    return;
}

void Turn::addStein(int pos_x, int pos_y, int farbe, int form) {
    Stein neuerStein = Stein(pos_x, pos_y, farbe, form);
    spielzug.push_back(neuerStein);
    return;
}

QJsonArray Turn::steineToJson() {
    QJsonArray steineJson;
    for (unsigned long i = 0; i < this->spielzug.size(); i++) {
        QJsonObject temp;
        temp.insert("pos_x", this->spielzug[i].pos_x);
        temp.insert("pos_y", this->spielzug[i].pos_y);
        temp.insert("farbe", this->spielzug[i].farbe);
        temp.insert("form", this->spielzug[i].form);
        steineJson.append(temp);
    }
    return steineJson;
}
