#include "std_lib_facilities.h"
#include "utilities.h"
#include "cannonball.h"
#include "cmath"

int randomWithLimits(int lowerLimit, int upperLimit){
    int randomNumber = rand() % upperLimit + lowerLimit;
    return randomNumber;
}

void playTargetPractice(){
    //Tar inn user input
    double theta = getUserInputTheta();
    double absVelocity = getUserInputAbsVelocity();
    //Finner avstanden til målet
    double distanceToTarget = randomWithLimits(100, 1000);
    //vektor med
    vector<double> velocityVector = getVelocityVector(theta, absVelocity);
    double velocityX = velocityVector[0];
    double velocityY = velocityVector[1];
    double flight_time = flightTime(velocityY);
    printTime(flight_time);
    cout << "Distanse: " << distanceToTarget << endl;
    //double velocity
    
    double distanceTraveled = getDistanceTraveled(velocityX, velocityY);
    cout << "Forskjell: " << targetPractice(distanceToTarget, velocityX, velocityY) << endl;
    
    int counter = 0;
    while(counter != 10){
        double tp = targetPractice(distanceToTarget, velocityX, velocityY); 
        if(tp <= 5 && tp > 0)
        {
            cout << "Du vant på " << counter + 1 << " forsøk!" << endl;
            break;
        }else if(tp > 5){
            cout << "Ingen treff, for kort." << endl;
        }else if(tp < 0){
            cout << "Ingen treff, for langt." << endl;
        }
        if(counter == 9){
            cout << "Game Over!" << endl;
        }
        //Tar inn ny user input
        double theta = getUserInputTheta();
        double absVelocity = getUserInputAbsVelocity();
        //Overskriver fartsvektoren
        velocityVector = getVelocityVector(theta, absVelocity);
        double velocityX = velocityVector[0];
        double velocityY = velocityVector[1];
        double flight_time = flightTime(velocityY);
        printTime(flight_time);
        cout << "Distanse: " << distanceToTarget << endl;
        cout << "Forskjell: " << targetPractice(distanceToTarget,velocityX,velocityY) << endl;

        counter++;

    }
    

}