#pragma once
#include "std_lib_facilities.h"
#include "utilities.h"
//Oppgave 1b)
int incrementByValueNumTimes(int startValue, int increment, int numTimes){
	for(int i = 0; i < numTimes; i++){
		startValue += increment;
	}
	return startValue;
}
//Oppgave 1d)
int incrementByValueNumTimesRef(int& startValue, int& increment, int& numTimes){
	for(int i = 0; i < numTimes; i++){
		startValue += increment;
	}
	return startValue;
}

//Oppgave 1e)
void swapNumbers(){
    //vanilla:
    int val1 = 1;
    int val2 = 2;
    //References
    int& val1_ref = val1;
    int& val2_ref = val2;
    int temp;
    //temp = val1;
    //val1 = val2;
    //val2 = temp;
    //With reference
    temp = val1_ref;
    val1 = val2_ref;
    val2_ref = temp;

    cout << "Value 1: " << val1 << endl
        << "Value 2: " << val2 << endl;
    cout << "Value 1 ref: " << val1_ref << endl
        << "Value 2 ref: " << val2_ref << endl;
    
}

//Oppgave 2b)
void printStudent(Student student){
    cout << "Navn: " << student.name << endl
        << "Studieprogram: " << student.studyProgram << endl
        << "Alder: " << student.age << endl;

}

//Oppgave 2c)
void isInProgram(Student student, string studyProgram){
    if(student.studyProgram == studyProgram){
        cout << student.name << " går på " << studyProgram << endl;
    }else{
        cout << student.name << " går ikke på " << studyProgram << endl;
    }
}
//Oppgave 3b)
string randomizedString(int length, int lowerLimit, int upperLimit){
    //Oppretter streng og char variabelen
    string randomizedString = "";
    char c;
    //int n = rand() % upperLimit + lowerLimit;
    for(int i = 0; i < length; i++){
        //generer en tilfeldig verdi ut ifra en øvre og nedre grense
        int n = rand() % upperLimit + lowerLimit;
        //måten vi oppretter en char ut ifra n
        c = 'A' + n - 1;
        //
        randomizedString += c;
    }

    return randomizedString;
}

//Oppgave 3f)
string readInputToString(int lowerLimit, int upperLimit, int n){
    //Opretter streng og char variabelen
    string s1 = "";
    char c;
    int num;
    while(n > 0){
        cout << "Skriv inn et tall mellom " << lowerLimit 
            << " og " << upperLimit << ": ";
        cin >> num;
        if(num >= lowerLimit && num <= upperLimit){
            c = 'A' + num - 1;
            s1 += c;
            n--;
        }else{
            cout << "Du har skrevet inn ugyldig input!" << endl;
            cout << "Skriv inn et tall mellom " << lowerLimit 
            << " og " << upperLimit << ": ";
            cin >> num;
        }
    }
    return s1;
}

//Oppgave 3g)
int countChar(string s1, char c1){
    int count = 0;
    for(unsigned int i = 0; i < s1.length(); i++){
        if(s1[i] == c1){
            count++;
        }
    }
    return count;
}
