#pragma once
#include "std_lib_facilities.h"
#include "utilities.h"
#include "masterVisual.h"
#include "Graph.h"
#include "Simple_window.h"
//using namespace Graph_lib;


//Oppgave 4e)
//Gjør det samme som hamming distance ;)
//Fungerer!!
int checkCharactersAndPosition(string code, string guess){
    //Hvis ulik størrelse:
    //int size = (code.size() + guess.size())/2;
    //Antar at code og guess har samme størrelse
    int count = 0;
    for(unsigned int i = 0; i < code.size(); i++){
        if(code.at(i) == guess.at(i)){
            count++;
        }
    }
    return count;
}
//Oppgave 4f)
//Du må bruke countChar
//WIP: må fikses
//Her må du sikker finne en måte å fjerne
//bokstavene fra code når du finner de i guess
int checkCharacters(string code, string guess){
    
    int count = 0;
    /*
    int occurrence1 = 0;
    int occurrence2 = 0;
    for(unsigned int i = 0; i < guess.size(); i++){
        //Sykt hvis dette funker
        occurrence1 = countChar(code, guess.at(i));
        occurrence2 = countChar(guess, guess.at(i));
        if(occurrence1 == occurrence2){
            count += occurrence1;
            cout << "De er like på " << guess.at(i) << endl;
        }else if(occurrence1 + 1 == occurrence2){
            count += occurrence1;
            cout << "Det er en 1 forskjell på " << guess.at(i) << endl;
        }else if(occurrence1 + 2 == occurrence2){
            count += occurrence1;
            cout << "Det er en 2 forskjell på " << guess.at(i) << endl;
        }else if(occurrence1 + 3 == occurrence2){
            count += occurrence1;
            cout << "Det er en 3 forskjell på " << guess.at(i) << endl;
        }else{
            count += 0;
        }
        //count += rightChars;
    }
    */
    return count;
}

//Oppgave 4a)
/**
 * Grunnen til at vi bruker constexpr og ikke const er
 * fordi vi bruker både size og letters, når dette
 * kjøres i utregning, slik at vi sparer ressurser
 * når programmet kjører.
 * const kan brukes på variabler som ikke skal brukes
 * ofte, men holdes konstante
*/
void playMastermind(){
    constexpr int lowerLimit = 1;
    constexpr int size = 4;
    constexpr int letters = 6;

    //Oppgave 5a):
    int winWidth = 500;
    int winHeight = 500;
    MastermindWindow mwin{Point{900,20}, winWidth, winHeight,"Mastermind"};

    //Oppgave 4b)
    string code;
    string guess;

    //Hjelpe variabler
    int countPositions;
    int countCharacters;
    //Oppgave 4i)
    int round = 1;

    //Oppgave 4c)
    code = randomizedString(size,lowerLimit,letters);
    //Oppgave 4d og 5a)
    guess = mwin.getInput(size,'A','F');
    addGuess(mwin, guess, size, guess[0], round);
    
    countPositions = checkCharactersAndPosition(code, guess);
    countCharacters = checkCharacters(code, guess);

    
    //Oppgave 4g og h)
    while(countPositions < size && round > 6){
        //Oppgave 4j)
        if(round == 6){
            cout << "Beklager! Du kan ikke være best i alt!" << endl;
            break;
        }
        cout << "Gjetning: " << guess << endl;
        cout << "Kode: " << code << endl;
        cout << "Antall like bokstaver og posisjoner: " << countPositions << endl;
        cout << "Antall like bokstaver" << countCharacters << endl;
        cout << "Prov igjen." << endl;

        //Rendrer på nytt før neste gjetning
        mwin.redraw();
        guess = mwin.getInput(size,'A','F');
        //addGuess(&mwin, code, size, guess, round);
        countPositions = checkCharactersAndPosition(code, guess);
        countCharacters = checkCharacters(code, guess);
        //Oppgave 4j)
        if(countPositions == size){
            cout << "Gratulerer! Du vant!" << endl;
            break;
        }
        round++;

    }
    //cout << "Kode: " << code << endl;
    //cout << "Antall like bokstaver og posisjoner: " << countPositions << endl;
}

