#pragma once

#include <iostream>
#include <ostream>
#include <list>

using namespace std;
class Person {
    string firstName;
    string surname;

public:
    Person(string firstName, string surname);
    void setFirstName(string firstName);
    string getFirstName() const;
    void setSurname(string firstName);
    string getSurname() const;
    friend ostream& operator<<(ostream& os, const Person& p);

    void insertOrdered(std::list<Person> &l, const Person& p);
};
