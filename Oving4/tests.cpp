#pragma once
#include "std_lib_facilities.h"
#include "utilities.h"

//Oppgave 1c)
void testCallByValue(){
	int v_start = 5;
	int increment = 2;
	int iterations = 10;
	int result = incrementByValueNumTimes(v_start, increment, iterations);
	cout << "v_start: " << v_start
		<< ", increment: " << increment
		<< ", iterations: " << iterations
		<< ", result: " << result << endl;
}
void testCallByValueRef(){
	int v_start = 5;
	int increment = 2;
	int iterations = 10;
	int result = incrementByValueNumTimesRef(v_start, increment, iterations);
	cout << "v_start: " << v_start
		<< ", increment: " << increment
		<< ", iterations: " << iterations
		<< ", result: " << result << endl;
}

void testString(){
	//Oppgave 3c og 3d)
	//Lagt til variabler for mer oversiktig kode
	int amountOfGrades = 8;
	int lowerLimit = 1;
	int upperLimit = 6;
	string grades = randomizedString(amountOfGrades,lowerLimit,upperLimit);
	//Oppgave 3e)
	cout << "Karakterer: " << grades << endl;

	//Oppgave 3h
	vector<int> gradeCount;
	//Hjelpevektorer for chars og poeng
	vector<char> chars = {'A','B','C','D','E','F'};
	vector<int> points = {5, 4, 3, 2, 1, 0};

	//Looper gjennom og setter forekomsten inn i gradeCount
	for(unsigned int i = 0; i < chars.size(); i++){
		gradeCount.push_back(countChar(grades, chars[i]));
	}

	//Opretter og teller opp total poengsum ved hjelp av gradeCount og points
	double totalPoints = 0.0;
	for(unsigned int i = 0; i < gradeCount.size(); i++){
		totalPoints += gradeCount.at(i)*points.at(i);
	}
	//Regner ut gjennomsnittet, og skriver ut poeng og gjennomsnitt
	double average = totalPoints/amountOfGrades;
	cout << "Totalt poeng er: " << totalPoints << endl;
	cout << "Gjennomsnittet er: " << average << endl;
}