#pragma once
#include "std_lib_facilities.h"
class Temps {
private:
    double max;
    double min;

public:
    Temps();
    Temps(double max, double min);
    friend istream& operator>>(istream& is, Temps& t);
    vector<Temps> readTemps(string filename);
    void tempStats(vector<Temps> temps);
};