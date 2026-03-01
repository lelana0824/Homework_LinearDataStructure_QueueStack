//
// Created by Lelana on 2026. 3. 1..
//
#include "Container/Vector.h"
#include "CardInfo.h"

#ifndef LINEARDATASTRUCTURE_QUEUESTACK_FLIPTHROUGHCARDSYSTEM_H
#define LINEARDATASTRUCTURE_QUEUESTACK_FLIPTHROUGHCARDSYSTEM_H


class FlipThroughCardSystem {
public:
    FlipThroughCardSystem();
    ~FlipThroughCardSystem();

    //시스템 클래스 Init(const char* filename)로 csv 파일 정보를 읽어 Info 동적 배열로 저장해두자.
    void Initialize(const char* fileName);

    //Run 함수로 내부에서는 private Show를 호출해서 첫 번째 인덱스 카드를 보여주자.
    //방향키 입력을 받아서 동작하도록 하자.
    void Run();
private:
    void ShowCard(int index);

    Vector<CardInfo*>* cards = nullptr;
};


#endif //LINEARDATASTRUCTURE_QUEUESTACK_FLIPTHROUGHCARDSYSTEM_H