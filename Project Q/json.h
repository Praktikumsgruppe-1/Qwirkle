#ifndef JSON_H
#define JSON_H
#include <QJsonArray>
#include <QJsonObject>
#include <vector>


class json
{
public:
    json();
    static QJsonArray toJson(const std::vector<int>);
};

#endif // JSON_H
