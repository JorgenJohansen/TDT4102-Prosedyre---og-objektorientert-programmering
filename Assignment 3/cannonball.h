//#pragma once
//Hvis vi importerer noe
//Oppgave 1a)
double acclY();
//Hjelpefunksjon
double acclX();

//Oppgave 1b)
double velY(double initVelocity, double time);

//Oppgave 1c)
double posX(double initPosition, double initVelocity, double time);
double posY(double initPosition, double initVelocity, double time);

//Oppgave 1d)

void printTime(double seconds);

//Oppgave 1e)
double flightTime(double initVelocityY);

//Oppgave 4a)
//Ber brukeren om en vinkel
double getUserInputTheta();

//Berbrukeren om en absoluttfart
double getUserInputAbsVelocity();

//Konverterer fra graer til radianer
double degToRad(double deg);

//Returnerer henholdsvis farten i x-, og y-retning, gitt en vinkel
//theta og en absoluttfart absVelocity
double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);

//Dekomponerer farten gitt av absVelocity, i x- og y-komponentene
// gitt vinkel theta. Det førstd elemenetet i vectoren skal være
// x-komponenten, og det andre elementet skal være y-komponenten.
// "Vector" i funksjonsnavnet er vektor-begrepet i geometri
vector<double> getVelocityVector(double theta, double absVelocity);

//Oppgave 4b)
double getDistanceTraveled(double velocityX, double velocityY);

//Oppgave 4c)
double targetPractice(double distanceToTarget, double veloctiyX, double velocityY);


