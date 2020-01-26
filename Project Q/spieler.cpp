#include "spieler.h"

Spieler::Spieler(){
    name = "";
    status = 0;
    position = 0;
};

std::string Spieler::getName(){
   return Spieler::name;
}

bool Spieler::getStatus() {
    return Spieler::status;
}

void Spieler::setName(std::string username) {
    Spieler::name = username;
    return;
}

void Spieler::setStatus(bool a) {
    Spieler::status = a;
    return;
}

void Spieler::setReihenfolge(int pos) {
    Spieler::position = pos;
    return;
}



