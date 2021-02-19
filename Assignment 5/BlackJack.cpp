
#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"
#include "BlackJack.h"

BlackJack::BlackJack()
{   
    //Setter opp spillet, sorterer kortene
    //og gir 2 kort til hver, og sorterer på nytt
    CardDeck cards{};
    cards.shuffle();
    cards.shuffle();
    cards.shuffle();
    addCardToPlayer(cards.drawCard());
    addCardToDealer(cards.drawCard());
    addCardToPlayer(cards.drawCard());
    addCardToDealer(cards.drawCard());
    cards.shuffle();
}

//Viser fram kortene til spiller
void BlackJack::displayPlayerHand(){
    for(unsigned int i = 0; i < playerHand.size(); i++){
        cout << playerHand.at(i).toString();
    }
}

//Viser fram kortene til dealer
void BlackJack::displayDealerHand(){
    for(unsigned int i = 0; i < dealerHand.size(); i++){
        cout << dealerHand.at(i).toString();
    }
}

//Legger til et kort til spilleren
//WIP: sjekker om det faktisk er noe å legge til
void BlackJack::addCardToPlayer(Card card){
    playerHand.push_back(card);
    /*
    if(&card != NULL){
        playerHand.push_back(card);
    }else{
        cout << "There is no card to give!" << endl;
    }
    */
}

//Legger til et kort til dealeren
//WIP: sjekker om det faktisk er noe å legge til
void BlackJack::addCardToDealer(Card card){
    dealerHand.push_back(card);
    /*
    if(&card != NULL){
        dealerHand.push_back(card);
    }else{
        cout << "There is no card to give!" << endl;
    }
    */
}

//Returnerer kortstokken
CardDeck BlackJack::getCardDeck(){
    return cards;
}
//returner poengene til spilleren
int BlackJack::getPlayerPoints(){
    int points = 0;
    for(unsigned int i = 0; i < playerHand.size(); i++){
        points += playerHand.at(i).getRank();
    }
    return points;
}
//Returnerer poengene til dealer
int BlackJack::getDealerPoints(){
    int points = 0;
    for(unsigned int i = 0; i < dealerHand.size(); i++){
        points += dealerHand.at(i).getRank();
    }
    return points;

}
