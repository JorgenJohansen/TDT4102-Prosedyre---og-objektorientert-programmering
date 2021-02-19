//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor
//#pragma once
#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"
#include "BlackJack.h"

//------------------------------------------------------------------------------'
void printRules(){
	cout << "Reglene for blackJack er som følger: " << endl
	<< "Hver person får 2 kort og det er et mål om å oppnå 21 poeng" << endl
	<< "Får spiller mer enn dette er hen ute";
}
//Tar inn spillers poeng, dealers poeng og objektet blackJack
//regner da ut 3 boolske variabler som må være true for å vinne spillet
//printer også ut hva spilleren vant på
void winning(int playerPoints, int dealerPoints, BlackJack blackJack){
	bool condition1 = playerPoints == 21 && dealerPoints != 21;
	bool condition2 = playerPoints > dealerPoints && playerPoints < 21;
	bool condition3 = playerPoints < 21 && dealerPoints > 21;
	if(condition1 || condition2 || condition3){
		cout << "Gratulerer, du vant!" << endl;
		if(condition1){
			cout << "Du fikk en BlackJack! " << endl;
			cout << "Dine kort: " << endl;
			blackJack.displayPlayerHand();
		}
		if(condition2){
			cout << "Du hadde en større sum en dealer og mindre en 21" << endl;
			cout << "Dine kort: " << endl;
			blackJack.displayPlayerHand();
		}
		if(condition3){
			cout << "Dealer gikk over 21 i poengsum, men det gjorde ikke du!" << endl;
			cout << "Dine kort: " << endl;
			blackJack.displayPlayerHand();
		}
		return;
	}
}
//Tar inn spillers poeng og objektet blackJack
//er spillers poeng over 21 taper spilleren
void losing(int playerPoints, BlackJack blackJack){
	if(playerPoints > 21){
		cout << "Dessverre er du ute med: " << endl;
		blackJack.displayPlayerHand();
		return;
	}
}

int main()
{
	cout << "Hello, World!\n";
	//Oppgave 1f)
	//Rank r = Rank::king;
	//Suit s = Suit::hearts;
	//string rank = rankToString(r);
	//string suit = suitToString(s);
	//cout << "Rank: " << rank << " Suit: " << suit << endl;

	//cout << Rank::two;
	/*
	enum Rank {two = 2,three, four, five, six, seven, eight,
                nine, ten, jack, queen, king, ace};

	
	cout << three;
	*/
	//Card c{Suit::clubs, Rank::king};
	//cout << c.toString();
	//cout << c.toStringShort();

	//cout << spades-clubs;
	//cout << (ace - two + 1) << endl;
	//Tester oppgave 3
	//Initialiserer konstruktøren
	//CardDeck cards{};
	//Oppgave 3d
	

	//cards.printShort();

	//cards.swap(0,12);
	//cards.printShort();

	//Card card = cards.drawCard();
	//cout << card.toString() << endl;
	//cout << card.getRank() << endl;

	//cards.print();
	//Shuffle dem cards!
	//cards.shuffle();
	//cards.shuffle();
	//cards.shuffle();
	//cards.shuffle();
	//cards.shuffle();
	//cards.shuffle();
	//cards.print();

	//Oppgave 4:
	srand(static_cast<unsigned int>(time(nullptr)));
	BlackJack blackJack {};
	CardDeck cards = blackJack.getCardDeck();
	//Kortene til spiller
	blackJack.displayPlayerHand();
	int playerPoints = blackJack.getPlayerPoints();
	cout << "Spilleren har " << playerPoints << " poeng" << endl;
	
	//Kortene til dealer
	blackJack.displayDealerHand();
	int dealerPoints = blackJack.getDealerPoints();
	cout << "Dealeren har " << dealerPoints << " poeng" << endl;
	
	while(playerPoints <= 21){
		//Sette dette i en funksjon
		winning(playerPoints, dealerPoints, blackJack);
		//Hvis spiller får over 21 er hen ute
		losing(playerPoints, blackJack);


		if(dealerPoints >= 17 && playerPoints < 21){ 
			cout << "Dealer må stå" << endl;
			blackJack.addCardToPlayer(cards.drawCard());
		}else if(dealerPoints < 17 && playerPoints < 21){
			//cout << "Hallo"<< endl;
			blackJack.addCardToPlayer(cards.drawCard());
			blackJack.addCardToDealer(cards.drawCard());
		}

		playerPoints = blackJack.getPlayerPoints();
		cout << "Spilleren har " << playerPoints << " poeng" << endl;
		dealerPoints = blackJack.getDealerPoints();
		cout << "Dealer har " << dealerPoints << " poeng" << endl;

	}

	keep_window_open();
}

//------------------------------------------------------------------------------
