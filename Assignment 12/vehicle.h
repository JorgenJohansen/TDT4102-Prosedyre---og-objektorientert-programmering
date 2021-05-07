#pragma once
#include <FL/Fl_Widget.h>
#include <tuple>
#include "utilities.h"
#include "track.h"

class Vehicle : Fl_Widget {
private:
    virtual void drawBody() const = 0;
protected:
    virtual std::pair<double,double> steer() const = 0;
    Track &track;
    PhysicsState physicsState;
    int goalIndex = 0;

public: 

    Vehicle(double x, double y, double angle, Track &track);
    virtual void draw() final;
};

class PlayerVehicle : public Vehicle{ 
private:
    
public:
    PlayerVehicle(double x, double y, double angle, Track &track);
    void drawBody() const;
    std::pair<double, double> steer() const override;
};

bool circleCollision(double delX, double delY, double sumR);