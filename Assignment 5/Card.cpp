//#pragma once
#include "std_lib_facilities.h"
#include "Card.h"

//Oppgave 1e)
/**
 * Enum begrenser compile-time sjekking og gir mer sikkerhet 
 * i forhold til hvilke konstanter vi kan gi
 * Kilde: https://beginnersbook.com/2017/09/cpp-enumeration/
*/

//Oppgave 1c)
string suitToString(Suit suit){
    map<Suit, string> suitMap;
    suitMap[Suit::clubs] = "Clubs";
    suitMap[Suit::diamonds] = "Diamonds";
    suitMap[Suit::hearts] = "Hearts";
    suitMap[Suit::spades] = "Spades";

    return suitMap[suit];
};

//Oppgave 1d)
string rankToString(Rank rank){
    map<Rank, string> rankMap;
    rankMap[Rank::two] = "Two";
    rankMap[Rank::three] = "Three";
    rankMap[Rank::four] = "Four";
    rankMap[Rank::five] = "Five";
    rankMap[Rank::six] = "Six";
    rankMap[Rank::seven] = "Seven";
    rankMap[Rank::eight] = "Eight";
    rankMap[Rank::nine] = "Nine";
    rankMap[Rank::ten] = "Ten";
    rankMap[Rank::jack] = "Jack";
    rankMap[Rank::queen] = "Queen";
    rankMap[Rank::king] = "King";
    rankMap[Rank::ace] = "Ace";

    return rankMap[rank];
};



Card::Card(Suit suit, Rank rank)
{
    s = suit;
    r = rank;
}

Suit Card::getSuit(){
    return s;
}

Rank Card::getRank(){
    return r;
}

string Card::toString(){
    return rankToString(r) + " of " + suitToString(s)  + "\n";
}


string Card::toStringShort(){
    string suit = suitToString(s);
    char color = suit[0];
    
    return to_string(color) + to_string(r) + "\n";
}


