#include "car.h"

//oppgave 1b)
Car::Car(int freeSeats) : freeSeats{freeSeats}{}


//Oppgave 1c)
bool Car::hasFreeSeats() const {
    if(freeSeats > 0){
        return true;
    }
    return false;
}

void Car::reserveFreeSeat(){
    freeSeats--;
}