//#pragma once
#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"

//Oppgave 3b)
//Funker
CardDeck::CardDeck()
{
    //spades-clubs+1 = 4
    for(unsigned int i = 0; i < (spades - clubs + 1); i++){
        //ace - two + 3 = 15
        for(unsigned int j = 2; j < (ace - two + 3); j++){
            //Legger objektet til vektoren
            cards.push_back(Card(Suit(i), Rank(j)));
        }
    }
}
//Oppgave 3c)
//Funker
void CardDeck::swap(unsigned int index1, unsigned int index2){
    /*
    Card card1 = cards.at(index1);
    Card card2 = cards.at(index2);
    Card temp = card1;
    //Bytter på kortene
    card1 = card2;
    card2 = temp;
    
    //Setter inn kortene
    cards[index1] = card1;
    cards[index2] = card2;
    */
    Card temp = cards[index1];
    cards[index1] = cards[index2];
    cards[index2] = temp;
        
    
    
}

//Oppgave 3d)
//Funker
void CardDeck::print(){
    for(unsigned int i = 0; i < cards.size(); i++){
        cout << cards.at(i).toString() << endl;
    }
}
//Oppgave 3e)
//Må testes
void CardDeck::printShort(){
    for(unsigned int i = 0; i < cards.size(); i++){
        cout << cards.at(i).toStringShort() << endl;
    }
}

//Oppgave 3f)
//Funker, men er nok ikke den beste akkurat
void CardDeck::shuffle(){
    
    for(unsigned int i = 0; i < cards.size(); i++){
        //unsigned int n = rand() % cards.size();
        unsigned int m = rand() % cards.size();
        swap(i, m);
    }   
}


//Oppgave 3g)
//Funker
Card CardDeck::drawCard(){
    //Henter ut det siste kortet
    Card draw = cards[cards.size()-1];
    //Sletter det fra lista
    cards.erase(cards.begin() + cards.size()-1);
    //Og returnerer det
    return draw;

}