#include "person.h"
//Oppgave 2a)
Person::Person(string firstName, string surname) : firstName{firstName}, surname{surname} {}

void Person::setFirstName(string f){
    firstName = f;
}

string Person::getFirstName() const {
    return firstName;
}

void Person::setSurname(string s){
    surname = s;
}

string Person::getSurname() const {
    return surname;
}

void Person::insertOrdered(std::list<Person> &l, const Person& p){
    //for(auto i = l.begin(); i != l.end(); i++){};
    l.insert(l.begin(), p);
}

ostream& operator<<(ostream& os, const Person& p){
    os << "Fornavn: " << p.getFirstName() << ", Etternavn: " << p.getSurname() << endl;
    return os;
}