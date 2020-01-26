#include "json.h"
#include <QJsonArray>
#include <QJsonObject>
#include <vector>

json::json()
{

}
QJsonArray json::toJson (const std::vector <int> vec){
    QJsonArray erg;
    for (auto i = vec.begin(); i!= vec.end(); i++) {
        erg.push_back((*i));
    }
    return erg;
}
