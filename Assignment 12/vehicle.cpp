#include "vehicle.h"
#include <FL/fl_draw.H>
#include <FL/Fl.H>
#include <iostream>;



Vehicle::Vehicle(double x, double y, double angle, Track &track) : Fl_Widget(10,10,10,10), track{track} {
    physicsState.x = x;
    physicsState.y = y;
    physicsState.angle = angle;
    
}

void Vehicle::draw(){
    std::pair<double,double> movement = steer();
    physicsState.update(movement.first, movement.second);
    drawBody();

    std::vector<std::pair<double,double>> goals = track.getGoals();
    double delX = goals[goalIndex].first - physicsState.x;
    double delY = goals[goalIndex].second - physicsState.y;
    double sumR = vehicleRadius + goalRadius;
    if(circleCollision(delX,delY,sumR)){
        if(goalIndex == goals.size()-1){
            goalIndex = 0;
        }
        fl_color(FL_RED);
        fl_circle(goals[goalIndex].first,goals[goalIndex].second, goalRadius);
        std::cout << "Mål: " << goalIndex + 1 << " truffet";
        goalIndex += 1;
        
    }
}



PlayerVehicle::PlayerVehicle(double x, double y, double angle, Track &track) : Vehicle(x, y, angle, track) {}

void PlayerVehicle::drawBody() const{
    fl_color(FL_GREEN);
    fl_line_style(0,5);
    fl_begin_polygon();
    fl_circle(physicsState.x, physicsState.y,vehicleRadius);
    fl_end_polygon();
    //draw();
}

std::pair<double, double> PlayerVehicle::steer() const {
    double verticalChange = 0;
    double horisontalChange = 0;
    std::pair<double,double> result;

    if(Fl::event_key(FL_Up)){
        verticalChange = 1;
    }
    if(Fl::event_key(FL_Down)){
        verticalChange = -1;
    }
    if(Fl::event_key(FL_Right)){
        horisontalChange = 1;
    }
    if(Fl::event_key(FL_Up)){
        horisontalChange = -1;
    }
    result.first = horisontalChange;
    result.second = verticalChange;
    return result;
    
}

bool circleCollision(double delX, double delY, double sumR){
    if((pow(delX,2) + pow(delY,2)) < pow(sumR,2)){
        return true;
    }else{
        return false;
    }
}
