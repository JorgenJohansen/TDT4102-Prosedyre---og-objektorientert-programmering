#pragma once
#include "Card.h"

class CardDeck {
    private:
        vector<Card> cards;
    public:
        CardDeck();
        void swap(unsigned int index1,unsigned int index2);
        void print();
        void printShort();
        void shuffle();
        Card drawCard();
};
