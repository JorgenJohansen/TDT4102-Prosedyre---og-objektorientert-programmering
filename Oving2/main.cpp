//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include <math.h>
#include "Graph.h"
#include "Simple_window.h"

//------------------------------------------------------------------------------'
//Oppgave 1a)
void intputAndPrintInteger(){
	int num;
	cout << "Skriv inn et tall: ";
	cin >> num;
	cout << "Du skrev: " << num << endl;
	return;
}
//oppgave 1b)
int inputInteger(){
	int num;
	cout << "Skriv inn et tall: ";
	cin >> num;
	return num;
}
//oppgave 1c)
void inputIntegersAndPrintSum(){
	int num1 = inputInteger();
	int num2 = inputInteger();
	int sum = num1 + num2; 
	cout << "Summen av tallene: " << sum << endl;
}

//Oppgave 1e)
bool isOdd(int num){
	if(num % 2 == 1){
		return true;
	}
	return false;
}

//Oppgave 1f)
//Kunne ha brukt ternary operator til å fikse
//grammatikken
void printHumanReadableTime(int sec){
	int hours = sec / 3600;
	int minutes = (sec % 3600) / 60;
	int seconds = sec % 60;
	
	cout << hours << " timer, " << minutes << " minutter og " << seconds << " sekunder." << endl;
	
}

//Oppgave 2a)
void readAndSum(){
	int numbers;
	int sum = 0;
	cout << " skriv inn hvor mange tall du vil summere: ";
	cin >> numbers;
	cout << "Du skal skrive inn " << numbers << " tall." << endl;
	while(numbers > 0){
		int num;
		cout << "Skriv inn et heltall: ";
		cin >> num;
		sum += num;
		numbers--;
	}
	cout << "Summen: " << sum << endl;
	return;
}

//Oppgave 2b)
void readAndSumContinued(){
	int num;
	int sum = 0;
	cout << "Skriv 0 for å avslutte." << endl;
	cout << "Skriv inn et heltall: "; 
	cin >> num;
	sum += num;
	while(num != 0){
		cout << "Skriv inn et heltall: ";
		cin >> num;
		sum += num;
	}
	cout << "Summen: " << sum << endl;
	return;
}

//Oppgave 2d)
double inputDouble(){
	double num;
	cout << "Skriv inn et tall: ";
	cin >> num;
	return num;
}

//Oppgave 2e)
double convertFromNOKtoEuro(){
	double num = inputDouble();
	double in_euros;
	//Kursen for euro sist gang jeg sjekket
	constexpr double exchange_rate = 10.32;
	while(num < 0){
		cout << "Du må skrive inn et positivt tall" << endl;
		num = inputDouble();
	}
	in_euros = num / exchange_rate;
	return in_euros;
}

//Støttefunksjon oppgave 3a)
void printMenu(){
	cout << endl;
	cout << "Velg funksjon: " << endl;
	cout << "0) Avslutt " << endl;
	cout << "1) Summer to tall" << endl;
	cout << "2) Summer flere tall" << endl;
	cout << "3) Konverter NOK til EURO" << endl;
	cout << "4) Løs andregradsligning" << endl;
	cout << "5) Regn ut rente" << endl;
	cout << "Angi valg (0-5): ";
	//cout << endl;
}

//Oppgave 3b)
void printMultiplicationTable(int n){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <=n; j++){
			cout << setw(5) << i * j;
		}
		cout << endl;
	}
}

//Oppgave 4a)
double discriminant(double a, double b, double c){	
	return pow(b,2.0)-(4*a*c);
}

//Oppgave 4b)
void printRealRoots(double a, double b, double c){
	if(discriminant(a,b,c) > 0){
		double x1 = (-b + sqrt(discriminant(a,b,c))/(2*a));
		double x2 = (-b - sqrt(discriminant(a,b,c))/(2*a));
		cout << "Ligningen har to reelle løsninger: " << endl;
		cout << "x1: " << x1 << endl;
		cout << "x2: " << x2 << endl;
	}else if(discriminant(a,b,c) == 0){
		double x = (-b/(2*a));
		cout << "Ligningen har en reell løsninger: " << endl;
		cout << "x: " << x << endl;
	}else{
		cout << "Ligningen har ingen reelle løsninger" << endl;
	}
}
//Oppgave c)
void solveQuadraticEquation(){
	double a;
	double b;
	double c;
	cout << "Skriv inn a: ";
	cin >> a;
	cout << "Skriv inn b: ";
	cin >> b;
	cout << "Skriv inn c: ";
	cin >> c;
	printRealRoots(a,b,c);
}
//Oppgave 5a)
/**
 * Kommentar: jeg kunne godt ha lagret Point i ulike
 * variabler for å gjort det lettere å lese koden
 * og endre på den
*/
void pythagoras(){
	using namespace Graph_lib;
	int width = 800;
	int height = 800;
	Simple_window window{Point{100, 100}, width, height, "Pythagoras"};
	
	Text b {Point{305,400},"B"};
	b.set_label("B");
	b.set_color(Color::green);
	b.set_fill_color(Color::green);
	
	Text a {Point{400,490},"A"};
	a.set_label("A");
	a.set_color(Color::red);
	a.set_fill_color(Color::red);
	
	Text c {Point{410,400},"C"};
	c.set_label("C");
	c.set_color(Color::black);
	c.set_fill_color(Color::black);

	

	Polygon rightTriangle;
	rightTriangle.add(Point{300,300});
	rightTriangle.add(Point{300,500});
	rightTriangle.add(Point{500,500});

	rightTriangle.set_color(Color::white);
	rightTriangle.set_fill_color(Color::black);

	Polygon bottomRectangle;
	//Dette punktet deles med rightTriangle
	bottomRectangle.add(Point{300,500});
	//Dette punktet deles med rightTriangle
	bottomRectangle.add(Point{500,500});
	bottomRectangle.add(Point{500,700});
	bottomRectangle.add(Point{300,700});

	bottomRectangle.set_fill_color(Color::red);

	Polygon leftRectangle;
	//Startpunktet vårt som deles med rightTriangle
	leftRectangle.add(Point{300,300});
	//Dette punktet deles med rightTriangle
	leftRectangle.add(Point{300,500});
	leftRectangle.add(Point{100,500});
	leftRectangle.add(Point{100,300});

	leftRectangle.set_fill_color(Color::green);

	//Figur for å hjelpe å tegne det blå rektangelet
	Polygon helperTriangle1;
	helperTriangle1.add(Point{500,500});
	helperTriangle1.add(Point{700,500});
	//Dette punktet brukes av i det blå rektanglet
	helperTriangle1.add(Point{700,300});

	helperTriangle1.set_color(Color::white);

	//Figur for å hjelpe å tegne det blå rektangelet
	Polygon helperTriangle2;
	helperTriangle2.add(Point{300,300});
	helperTriangle2.add(Point{300,100});
	//Dette punktet brukes av i det blå rektanglet
	helperTriangle2.add(Point{500,100});

	helperTriangle2.set_color(Color::white);

	Polygon rightRectangle;
	//Dette punktet deles med rightTriangle
	rightRectangle.add(Point{300,300});
	//Dette punktet deles med rightTriangle
	rightRectangle.add(Point{500,500});
	//Dette punktet er nederst
	rightRectangle.add(Point{700,300});
	//Dette punktet er øverst
	rightRectangle.add(Point{500,100});

	rightRectangle.set_fill_color(Color::blue);

	
	window.attach(rightTriangle);
	window.attach(bottomRectangle);
	window.attach(leftRectangle);
	window.attach(rightRectangle);
	window.attach(b);
	window.attach(a);
	window.attach(c);
	window.attach(helperTriangle1);
	window.attach(helperTriangle2);
	
	//Brukt for å lage et rektangel i starten
	/*
	Polygon testRectangle;
	testRectangle.add(Point{200,200});
	testRectangle.add(Point{400,200});
	testRectangle.add(Point{400,400});
	testRectangle.add(Point{200,400});

	testRectangle.set_fill_color(Color::blue);

	window.attach(testRectangle);
	*/

	
	window.wait_for_button();



}


//Oppgave 6a
vector<int> calculateBalance(){
	int balance, interest, time;
	cout << "Skriv inn beløp: ";
	cin >> balance;
	cout << "Skriv inn rente: ";
	cin >> interest;
	cout << "Skriv inn år: ";
	cin >> time;
	vector<int> balances(time + 1);
	for(int i = 0; i < time + 1; i++){
		balances[i] = balance * (pow((1 + static_cast<double>(interest)/100), i));
		//cout << i << setw(5) << ": " << balances[i] << endl;
	}
	return balances;
}
//Oppgave 6b)
void printBalance(){
	vector<int> balances = calculateBalance();
	cout << "Aar: " << "Saldo: "<< endl;
	for(unsigned int i = 0; i < balances.size(); i++){
		cout << setw(3) << i << " " << setw(5) << balances[i] << endl;
	}
	return;
}


// C++ programs start by executing the function main
int main()
{
	//Oppgave 1a)
	//intputAndPrintInteger();

	//Oppgave 1b)
	//int number = inputInteger();
	//cout << "Du skrev: " << number << endl;

	//Oppgave 1c)
	//inputIntegersAndPrintSum();

	//Oppgave 1d)
	/**
	 * Jeg valgte å bruke inputInteger fordi den
	 * returnerte heltallet jeg skulle bruke.
	 * intputAndPrintInteger er en void funksjon
	 * og har ikke mulighet til å brukes på den
	 * måten uten å skrives om siden den ikke 
	 * returnerer noe.
	*/

	//Oppgave 1e)
	//Tester med for loop og bruker unsigned int for
	//å slippe å få warning fra kompilator
	/*
	for(unsigned int i = 0; i < 16; i++){
		if(isOdd(i)){
			cout << i << " is odd." << endl;
		}else{
			cout << i << " is even." << endl;
		}
	}*/

	//Oppgave 1f)
	//WIP
	//printHumanReadableTime(10000);

	//Oppgave 2a)
	//readAndSum();

	//Oppgave 2b)
	//readAndSumContinued();

	//Oppgave 2c)
	/**
	 * I begge oppgave egner det seg best å bruke
	 * while looper for å finne når man skal terminere
	 * loopen. Det går an å bruke "for loop" i oppgave a)
	 * også, men det vil ikke egne seg for oppgave b)
	 * 
	*/

	//Oppgave 2d)
	//double number = inputDouble();
	//cout << "Du skrev inn: " << number << endl;

	//Oppgave 2e)
	//double euros = convertFromNOKtoEuro();
	//cout << fixed << setprecision(2) << euros << endl;

	//Oppgave 2f)
	/**
	 * Siden vi fortsatt har øre i NOK må vi ta
	 * hensyn til det med bruk av inputDouble,
	 * som ville gitt oss feil resultat om vi skulle
	 * kovertert til Euro
	 * Returtypen er double siden vi kan både ha
	 * et flytall for NOK og kursen vi er gitt
	*/



	//Oppgave 3a)
	/*
	int num;
	printMenu();
	//cin >> num;
	while(num != 0){
		double euros;
		cin >> num;
		switch(num){
			case 0:
				cout << "Du har avsluttet." << endl;
				break;
			case 1:
				inputIntegersAndPrintSum();
				printMenu();
				break;
			case 2:
				readAndSumContinued();
				printMenu();
				break;
			case 3:
				euros = convertFromNOKtoEuro();
				cout << fixed << setprecision(2) << euros << " Euro" << endl;
				printMenu();
				break;
			case 4:
				solveQuadraticEquation();
				printMenu();
				break;
			case 5:
				printBalance();
				printMenu();
				break;
			default:
				cout << "Ugyldig input!";
				printMenu();
				break;
		}
	}
	*/
	

	
	
	//Oppgave 3b)
	//printMultiplicationTable(5);


	//Oppgave 4a)
	//double dis = discriminant(2.0, 4.0, 1.0);
	//cout << dis << endl;
	 
	//Oppgave 4b)
	//Gir to reelle løsninger
	//printRealRoots(8.0, 4.0, -1.0);
	//Gir en reell løsning
	//printRealRoots(4.0, 4.0,1.0);
	//Gir ingen reelle løsninger
	//printRealRoots(1.0,2.0,4.0);

	//Oppgave 5
	pythagoras();


	//Oppgave 6a)
	
	
	//int balance = 10000;
	//int years = 10;
	//double interest = static_cast<double>(1 + static_cast<double>(5/100));
	//cout << setprecision(2) << interest << endl;
	//double futureBalance = balance * pow(interest, years);
	//cout << futureBalance << endl;

	//vector<int> balances = calculateBalance();
	//for(unsigned int i = 0; i < balances.size(); i++){
	//	cout << i << ": " << balances[i] << endl;
	//}
	//printBalance();

	

	keep_window_open();
}

//------------------------------------------------------------------------------
