//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"




//------------------------------------------------------------------------------'
void testDeviation(double compareOperand, double toOperand, double maxError, string name);
// C++ programs start by executing the function main
int main()
{
	
	

	//Oppgave 3b)
	//Tester resultatet
	//cout << setw(15) << " T = 0 " << setw(10) << " T = 2.5 " << setw(10) << " T = 5.0 " << endl;
	//cout << setw(1) << "acclX" << setw(5) << acclX() << setw(10) << acclX() << setw(10) << acclX() << endl;
	//cout << setw(1) << "acclY" << setw(8) << acclY() << setw(10) << acclY() << setw(10) << acclY() << endl;
	//cout << setw(1) << "velY" << setw(7) << velY(25.0,0.0) << setw(12) << velY(25.0,2.5) << setw(12) << velY(25.0,5.0) << endl;
	//cout << setw(1) << "posX" << setw(6) << posX(0.0, 25.0, 0.0) << setw(12) << posX(0.0, 25.0, 2.5) << setw(10) << posX(0.0, 25.0, 5.0) << endl;
	//cout << setw(1) << "posY" << setw(6) << posY(0.0, 25.0, 0.0) << setw(14) << posY(0.0,25.0,2.5) << setw(10) << posY(0.0,25.0,5.0) << endl;
	
	//double constexpr maxError = 0.0001;
	//cout << "posY: " << posY(0.0,25.0,5.0) << endl;
	//cout << "velY: " << velY(25.0,5.0) << endl;
	//testDeviation(posX(0.0,50.0,5.0), 250.0, maxError, "posX(0.0,50.0,5.0)");
	//testDeviation(posY(0.0,50.0,5.0), 2.375, maxError, "posX(0.0,50.0,5.0)");
	//testDeviation(velY(50.0,5.0), -24.05, maxError, "posX(0.0,50.0,5.0)");
	//Oppgave 5c)
	srand(static_cast<unsigned int>(time(nullptr)));

	//Oppgave 5b)
	//for(unsigned int i = 0; i < 20; i++){
	//	cout << randomWithLimits(1,10) << endl;
	//}

	//Oppgave 5d)
	//cout << getVelocityX(20,20) << endl;
	//cout << getVelocityY(20,20) << endl;
	//double theta = 20;
	//double absVelocity = 20;
	//vector<double> velocityVector = getVelocityVector(theta, absVelocity);
	//cout << velocityVector[0] << endl;
	//cout << velocityVector[1] << endl;

	double distanceToTarget = randomWithLimits(10,100);
	double velocityX = getVelocityX(20,20);
	double velocityY = getVelocityY(20,20);

	//cout << targetPractice(distanceToTarget,velocityX, velocityY) << endl;

	playTargetPractice();

	keep_window_open();
}

void testDeviation(double compareOperand, double toOperand, double maxError, string name){
	if(compareOperand - toOperand < maxError){
		cout << name << " er tilnærmet lik " << toOperand << endl;
	}else{
		cout << name << " er ikke tilnærmet lik " << toOperand << endl;
	}
}

//------------------------------------------------------------------------------
