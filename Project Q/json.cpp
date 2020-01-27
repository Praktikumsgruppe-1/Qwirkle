/**********************************************************************/
// Datei: json.cpp
// Programmebeschreibung:
/**********************************************************************/
#include "json.h"
#include <QJsonArray>
#include <QJsonObject>
#include <vector>

json::json()
{

}

QJsonArray json::toJson (const std::vector <int> vec)
{
    QJsonArray erg;
    for (auto i = vec.begin(); i!= vec.end(); i++)
    {
        erg.push_back((*i));
    }
    return erg;
}

std::vector <int> toVector(QJsonArray ar)
{
    std::vector <int> vec;
    int anz = ar.size();
    int tmp;
    //ganzes QJsonArray durchgehen
    for (int i = 0; i < anz; i++)
    {
        tmp = ar[i].toInt();
        vec.push_back(tmp);
    }
    return vec;
}
