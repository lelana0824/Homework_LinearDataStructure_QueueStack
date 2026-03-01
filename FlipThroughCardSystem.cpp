//
// Created by Lelana on 2026. 3. 1..
//

#include "FlipThroughCardSystem.h"
#include <cstdio>
#include <iostream>
#include <sstream>
#include <termios.h>
#include <unistd.h>

// 터미널 입력을 즉시 받기 위한 로우 레벨 환경 설정 함수 (macOS/Linux 정석)
int GetCh() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt); // 현재 터미널 설정 백업
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // 캐논 모드(엔터 대기)와 에코(화면 출력) 비활성화
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // 새 설정 즉시 적용
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // 원래 설정 복구
    return ch;
}

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
    if (!cards || cards->IsEmpty()) return;

    int currentIndex = 0;
    ShowCard(currentIndex);

    while (true) {
        int key = GetCh();

        // Unix 환경에서 방향키는 ESC(27)로 시작하는 3바이트 시퀀스를 생성합니다.
        if (key == 27) {
            int next1 = GetCh();
            int next2 = GetCh();

            if (next1 == 91) { // '[' 문자
                if (next2 == 67) { // Right Arrow (오른쪽 방향키)
                    if (currentIndex < cards->Size() - 1) {
                        currentIndex++;
                    } else {
                        currentIndex = 0;
                    }


                }
                else if (next2 == 68) { // Left Arrow (왼쪽 방향키)
                    if (currentIndex > 0) {
                        currentIndex--;
                    } else {
                        currentIndex = cards->Size() - 1;
                    }
                }
                system("clear");
                ShowCard(currentIndex % cards->Size());
            }
        }
    }
}

void FlipThroughCardSystem::ShowCard(int index) {
    cards->at(index)->Show();
}