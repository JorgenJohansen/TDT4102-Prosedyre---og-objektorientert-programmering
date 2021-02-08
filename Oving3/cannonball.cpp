#include "std_lib_facilities.h"
#include "cannonball.h"
#include "cmath"

//Oppgave 2a)
double acclY(){
    return -9.81;
}
//Hjelpefunksjon
double acclX(){
    return 0;
}
//oppgave 2b)
double velY(double initVelocity, double time){
    double velY = initVelocity + acclY()*time;
    return velY;
}
//oppgave 2c)
double posX(double initPosition, double initVelocity, double time){
    double position = initPosition + initVelocity * time + (acclX()*pow(time,2))/2;
    return position;
}

double posY(double initPosition, double initVelocity, double time){
    double position = initPosition + initVelocity * time + (acclY()*pow(time,2))/2;
    return position;
}

//oppgave 2d)
void printTime(double time){//time is seconds
    int hours = static_cast<int>(time) / 3600;
	int minutes = (static_cast<int>(time) % 3600) / 60;
	int seconds = static_cast<int>(time) % 60;
	
	cout << hours << " timer, " << minutes << " minutter og " << seconds << " sekunder." << endl;
}


//oppgave 2e)
double flightTime(double initVelocityY){
    double time = (-2*initVelocityY)/acclY();
    return time;
}

//Oppgave 4a)

double getUserInputTheta(){
    double theta;
    cout << "Skriv inn vinkel: ";
    cin >> theta;
    return theta;
}

double getUserInputAbsVelocity(){
    double absVelocity;
    cout << "Skriv inn startfarten: ";
    cin >> absVelocity;
    return absVelocity;
}

double degToRad(double deg){
    //It's so rad!
    double rad = ( deg * _Pi)/180;
    return rad;
}

double getVelocityX(double theta, double absVelocity){
    double velocityX = absVelocity * cos(degToRad(theta));
    return velocityX;
}
double getVelocityY(double theta, double absVelocity){
    double velocityY = absVelocity * sin(degToRad(theta));
    return velocityY;
}

vector<double> getVelocityVector(double theta, double absVelocity){
    vector<double> velocityVector(2);
    double velocityX = getVelocityX(theta, absVelocity);
    double velocityY = getVelocityY(theta, absVelocity);
    //cout << velocityX << endl;
    //cout << velocityY << endl;
    velocityVector[0] = velocityX;
    velocityVector[1] = velocityY;
    //velocityVector.push_back(velocityX);
    //velocityVector.push_back(velocityY);
    return velocityVector;
}
//Her må du regne deg fram
double getDistanceTraveled(double velocityX, double velocityY){
    double flight_time = flightTime(velocityY);
    double pos_Y = posY(0.0, velocityY, flight_time);
    return posX(0.0, velocityX, flight_time);
    
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY){
    double flight_time = flightTime(velocityY);
    //cout << flight_time << endl;
    double pos_x = posX(0.0, velocityX, flight_time);
    //cout << pos_x << endl;
    //cout << distanceToTarget << endl;
    return distanceToTarget - pos_x;
}


