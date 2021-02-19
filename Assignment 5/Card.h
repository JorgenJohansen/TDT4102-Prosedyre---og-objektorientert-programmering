#pragma once
#include "std_lib_facilities.h"

//Oppgave 1a)
//enum class lager bare problemer
enum Suit {clubs, diamonds, hearts, spades};

//Oppgave 2b)
enum Rank {two = 2, three, four, five, six, seven, eight,
                nine, ten, jack=10, queen=10, king=10, ace=11};

string suitToString(Suit s);
string rankToString(Rank r);

class Card {
private:
    Suit s;
    Rank r;
public:
    Card(Suit suit, Rank rank);
    Suit getSuit();
    Rank getRank();
    string toString();
    string toStringShort();
};
