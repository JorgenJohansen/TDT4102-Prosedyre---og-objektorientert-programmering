#pragma once
//Oppgave 1b)
int incrementByValueNumTimes(int startValue, int increment, int numTimes);
//Oppgave 1d)
int incrementByValueNumTimesRef(int& startValue, int& increment, int& numTimes);
//Oppgave 1e)
void swapNumbers();

//Oppgave 2a)
struct Student
{
   string name;
   string studyProgram;
   int age; 
};
//Oppgave 2b)
void printStudent(Student student);
//Oppgave 2c)
void isInProgram(Student student, string studyProgram);

//Oppgave 3b)
string randomizedString(int length, int lowerLimit, int upperLimit);

//Oppgave 3f
string readInputToString(int lowerLimit, int upperLimit, int n);

//Oppgave 3g)
int countChar(string s1, char c1);



