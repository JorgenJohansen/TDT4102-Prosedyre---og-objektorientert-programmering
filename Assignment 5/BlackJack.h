#pragma once
#include "Card.h"
#include "CardDeck.h"

class BlackJack {
    private:
        vector<Card> playerHand;
        vector<Card> dealerHand;
        CardDeck cards{};
    public:
        
        BlackJack();
        //Card deal();
        void displayPlayerHand();
        void displayDealerHand();
        void addCardToPlayer(Card card);
        void addCardToDealer(Card card);
        CardDeck getCardDeck();
        int getPlayerPoints();
        int getDealerPoints();
        
};
