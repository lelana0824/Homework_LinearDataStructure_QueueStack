//
// Created by Lelana on 2026. 3. 1..
//

#include "CardInfo.h"

#include <cstring>
#include <iostream>

CardInfo::CardInfo(int id, char* name, char* type, int cost, int rarity)
    : id(id), cost(cost), rarity(rarity) {
    int charLength = strlen(name);
    char* newName = new char[charLength + 1];

    strcpy(newName, name);
    this->name = newName;

    int typeLength = strlen(type);
    char* newType = new char[typeLength + 1];

    strcpy(newType, type);
    this->type = newType;
}

CardInfo::~CardInfo() {
    if (name) {
        delete[] name;
        name = nullptr;
    }
    if (type) {
        delete[] type;
        type = nullptr;
    }
}
void CardInfo::Show() const {
    std::cout << "-----------------------" << "\n";
    std::cout << "----No:     " << id << "----------" << "\n";
    std::cout << "----Name:   " << name << "(" << type << ")" << "\n";
    std::cout << "----cost:   " << cost << "----------" << "\n";
    std::cout << "----rarity: " << rarity << "----------" << "\n";
    std::cout << "-----------------------" << "\n";

}
