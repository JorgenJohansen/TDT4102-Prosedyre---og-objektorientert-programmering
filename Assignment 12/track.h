#pragma once
#include "utilities.h"
#include <FL/Fl_Widget.H>
#include <tuple>
#include <vector>

class Track : public Fl_Widget {
private:
    std::vector<std::pair<double,double>> goals;

public:
    Track();
    void draw() override;
    std::vector<std::pair<double,double>> &getGoals();
};