//
// Created by Lelana on 2026. 3. 1..
//

#include "CardInfo.h"

#include <cstring>
#include <iostream>

CardInfo::CardInfo(int id, char* name, char* type, int cost, int rarity)
    : id(id), cost(cost), rarity(rarity) {
    int charLength = sizeof(name) / sizeof(char);
    char* newName = new char[charLength + 1];

    strcpy(name, newName);
    this->name = newName;

    int typeLength = sizeof(type) / sizeof(char);
    char* newType = new char[typeLength + 1];

    strcpy(type, newType);
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
    std::cout << "------------------------" << "\n";
    std::cout << "-----------" << id << "----------" << "\n";
    std::cout << "------------------------" << "\n";
    std::cout << "-----------" << name << "----------" << "\n";
    std::cout << "------------------------" << "\n";
    std::cout << "------------------------" << "\n";
    std::cout << "------------------------" << "\n";
    std::cout << "-----------" << cost << "----------" << "\n";
    std::cout << "-----------" << rarity << "----------" << "\n";
    std::cout << "------------------------" << "\n";
    std::cout << "------------------------" << "\n";
    std::cout << "------------------------" << "\n";
    std::cout << "------------------------" << "\n";

}
