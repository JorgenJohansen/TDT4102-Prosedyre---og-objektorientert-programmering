#include "person.h"

//Oppgave 2b)
Person::Person(string name, string email, Car* car) : 
name{name}, email{email}, car{car} {}


string Person::getName() const {
    return name;
}

string Person::getEmail() const {
    return email;
}

void Person::setEmail(string newEmail){
    email = newEmail;
}
//Oppgave 2c)
bool Person::hasAvailableSeats(){
    if(car != nullptr && car->hasFreeSeats()){
        return true;
    }
    return false;
}

//Oppgave 2d)
/**
 * Grunnen til at vi bruker const er fordi vi ikke 
 * endrer på person objektet i funksjonen,
 * Skulle vi ha endret på det underveis må vi ta vekk
 * "const" ordet
*/
ostream& operator<<(ostream& os, const Person& p){
    os << "Navn: " << p.getName() << ", e-post: " << p.getEmail() << endl;
    return os;
}