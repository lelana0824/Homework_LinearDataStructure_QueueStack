//
// Created by Lelana on 2026. 3. 1..
//

#ifndef LINEARDATASTRUCTURE_QUEUESTACK_CARDINFO_H
#define LINEARDATASTRUCTURE_QUEUESTACK_CARDINFO_H


class CardInfo {
public:
    CardInfo(int id, char* name, char* type, int cost, int rarity);
    ~CardInfo();
    void Show() const;

private:
    int id;
    char* name;
    char* type;
    int cost;
    int rarity;
};


#endif //LINEARDATASTRUCTURE_QUEUESTACK_CARDINFO_H