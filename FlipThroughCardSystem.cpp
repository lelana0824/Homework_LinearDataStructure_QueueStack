//
// Created by Lelana on 2026. 3. 1..
//

#include "FlipThroughCardSystem.h"
#include <cstdio>
#include <iostream>
#include <sstream>

FlipThroughCardSystem::FlipThroughCardSystem() {
    cards = new Vector<CardInfo *>;
}

FlipThroughCardSystem::~FlipThroughCardSystem() {
    if (cards) {
        delete[] cards;
        cards = nullptr;
    }
}
void FlipThroughCardSystem::Initialize(const char* fileName) {
    FILE* file = fopen(fileName, "rt");

    if (file == nullptr) {
        std::cout << "Failed to open file: " << fileName << "\n";
        return;
    }

    char buffer[1024] = { 0 };
    int lineNumber = 0;

    while (fgets(buffer, sizeof(buffer), file) != nullptr) {
        if (lineNumber > 0) {
            char* token = strtok(buffer, ",");
            if (!token) continue;
            int id = std::atoi(token);

            token = strtok(nullptr, ",");
            if (!token) continue;

            int nameLen = 0;
            while (token[nameLen] != '\0') nameLen++;
            char* name = new char[nameLen + 1];
            for (int i = 0; i <= nameLen; ++i) {
                name[i] = token[i];
            }

            token = strtok(nullptr, ",");
            if (!token) continue;

            int typeLen = 0;
            while (token[typeLen] != '\0') typeLen++;
            char* type = new char[typeLen + 1];
            for (int i = 0; i <= typeLen; ++i) {
                type[i] = token[i];
            }

            token = strtok(nullptr, ",");
            if (!token) continue;
            int cost = std::atoi(token);

            token = strtok(nullptr, ",");
            if (!token) continue;
            int rarity = std::atoi(token);

            cards->Pushback(new CardInfo(id, name, type, cost, rarity));

            delete[] name;
            delete[] type;
        }

        lineNumber++;
    }

    fclose(file);
}

//Run 함수로 내부에서는 private Show를 호출해서 첫 번째 인덱스 카드를 보여주자.
//방향키 입력을 받아서 동작하도록 하자.
void FlipThroughCardSystem::Run() {
    if (!cards) return;

    ShowCard(0);
}

void FlipThroughCardSystem::ShowCard(int index) {
    cards->at(index)->Show();
}