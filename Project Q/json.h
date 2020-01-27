#ifndef JSON_H
#define JSON_H
#include <QJsonArray>
#include <QJsonObject>
#include <QVector>


class json
{
public:
    json();
    static QJsonArray toJson(const std::vector<int>);
    static std::vector <int> toVec(QJsonArray);

};

#endif // JSON_H
