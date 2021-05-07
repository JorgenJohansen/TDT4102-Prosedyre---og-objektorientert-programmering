#include "dummy.h"
#include "iostream"
using namespace std;
//Oppgave 3a)
//Antar at det først skrives
//ut 4 og etterpå bare skrives
//5 siden vi bruker shallow copying
//
//Det var det som skjedde

//Oppgave 3b)
void dummyTest(){
    Dummy a;
    *a.num = 4;
    Dummy b{a};
    Dummy c;
    c = a;
    cout << "a:" << *a.num << "\n";
    cout << "b:" << *b.num << "\n";
    cout << "c:" << *c.num << "\n";

    *b.num = 3;
    *c.num = 5;
    
    cout << "a:" << *a.num << "\n";
    cout << "b:" << *b.num << "\n";
    cout << "c:" << *c.num << "\n";
}