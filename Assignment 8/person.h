#pragma once
#include "std_lib_facilities.h"
#include "car.h"
//Oppgave 2a)
class Person {
private:
    string name;
    string email;
    Car* car;
public:
    Person(string name, string email, Car* car = nullptr);
    string getName() const;
    string getEmail() const;
    void setEmail(string newEmail);
    bool hasAvailableSeats();
    friend ostream& operator<<(ostream& os, const Person& p);

};