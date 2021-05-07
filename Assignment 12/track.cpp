
#include "track.h"
#include <FL/fl_draw.H>

Track::Track() : Fl_Widget(10,10,10,10){
    double x,y;
    //For loop for diagonal fra  høyre topp til venstre bunn
    
    for(int i = 0; i < 10; i++){
        x = abs(cos(100))*(100+100*i);
        y = abs(cos(100)*sin(100))*(100+100*i);
        if(x < screenWidth && x > 0 && y < screenHeight && y > 0){
            goals.push_back(std::make_pair(x,y));
        }
    }
    

    //For loop høyre side
    for(int i = 0; i < 5; i++){
        x = abs(cos(100))*(100+100*10);
        y = abs(cos(100)*sin(100))*(1000-2*i*100);
        if(x < screenWidth && x > 0 && y < screenHeight && y > 0){
            goals.push_back(std::make_pair(x,y));
        }
    }

    //For loop for diagonal fra  venstre topp til høyre bunn
    for(int i = 0; i < 10; i++){
        x = abs(cos(100))*(1000-100*i);
        y = abs(cos(100)*sin(100))*(100+100*i);
        if(x < screenWidth && x > 0 && y < screenHeight && y > 0){
            goals.push_back(std::make_pair(x,y));
        }
    }

    //For loop venstre side
    for(int i = 0; i < 5; i++){
        x = abs(cos(100))*(100);
        y = abs(cos(100)*sin(100))*(2*i*100);
        if(x < screenWidth && x > 0 && y < screenHeight && y > 0){
            goals.push_back(std::make_pair(x,y));
        }
    }


}

void Track::draw() {
    fl_color(FL_GRAY);
    for(unsigned int i = 0; i < goals.size(); i++){
        fl_circle(goals[i].first,goals[i].second,goalRadius);
    }
    
}

std::vector<std::pair<double,double>> &Track::getGoals(){
    return goals;
}
