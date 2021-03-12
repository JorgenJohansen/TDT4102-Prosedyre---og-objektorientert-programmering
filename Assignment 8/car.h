#pragma once
#include "std_lib_facilities.h"
//Oppgave 1a)
class Car {
private:
    int freeSeats;
public:
    bool hasFreeSeats() const;
    void reserveFreeSeat();
    Car(int freeSeats);
};