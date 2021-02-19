//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor
#pragma once
#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"
#include "mastermind.h"

//------------------------------------------------------------------------------'
//Oppgave 1a)
/**
 * Vi legger til 2 for hver iterasjon, som totalt er 20
 * det gjør at 
*/

void printMenu(){
	cout << "Angi valg (0-1)" << endl
		<< "Trykk 0 for å avslutte" << endl
		<< "Trykk 1 for utregning" << endl
		<< "Trykk 2 for utregning med referanse" << endl
		<< "Trykk 3 for å bytte nummer" << endl
		<< "Trykk 4 for å spille Mastermind" << endl;
}

void menuSystem(){
	printMenu();
	int val;
	cout << "Skriv inn tall: ";
	cin >> val;
	while(val != 0){
		switch(val){
			case 0:
				cout << "Du valgte å avslutte.";
				break;
			case 1:
				testCallByValue();
				break;
			case 2:
				testCallByValueRef();
				break;
			case 3:
				swapNumbers();
				break;
			case 4:
				playMastermind();
				break;
			default:
				cout << "Ugyldig input" << endl;
				break;
		}
		printMenu();
		cout << "Skriv inn tall: ";
		cin >> val;
	}
}


// C++ programs start by executing the function main
int main()
{
	/*
	Prøver å fikse nordic letters
	#ifdef _WIN32
	SetConsoleOutputCP(1252);
	#endif
	*/
	//Oppgave 1c)
	
	//menuSystem();

	//Oppgave 2
	Student student1;
	student1.name = "Jorgen Johansen";
	student1.studyProgram = "BIT";
	student1.age = 26;

	//printStudent(student1);
	//isInProgram(student1, "MKDA");
	//MKDA er et interiør firma
	//eller Mortal Kombat: Deadly Alliance

	//Oppgave 3b)
	//srand(static_cast<unsigned int>(time(nullptr)));
	//testString();

	//Oppgave 3f)
	//string s1 = readInputToString(1,6,4);
	//cout << s1 << endl;

	//Oppgave 3g)
	//int count = countChar("ABBA",'C');	
	//cout << count << endl;

	//Oppgave 3h)
	srand(static_cast<unsigned int>(time(nullptr)));
	//testString();

	//Oppgave 4e)
	//playMastermind();
	
	//cout << "Before: " << s1 << endl;
	//s1.erase(s1.begin());
	//cout << "After: " << s1 << endl;
	/*
	string s1 = "ABBA";
	vector<int> indexes;
	for(unsigned int i = 0; i < s1.size(); i++){
		if(s1.at(i) == 'A'){
			indexes.push_back(i);
		}
	}
	cout << indexes.size() << endl;
	cout << "Before: " << s1 << endl;
	s1.erase(s1.begin() + 0, s1.begin() + 3);
	
	
	for(unsigned int i = 0; i < indexes.size(); i++){
		cout << indexes.at(i) << endl;
		s1.erase(s1.begin() + indexes.at(i));
		cout << "In loop: " << s1 << endl;
	}
	
	cout << "After: " << s1 << endl;
	*/
	playMastermind();


	keep_window_open();
}

//------------------------------------------------------------------------------
