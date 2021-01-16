//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor
//oppgave 1a)
/*
//Har testet denne i idle(Python 3)
def isFibonacciNumber(n):
	a = 0
	b = 1
	while(b < n):
		temp = b
		b += a
		a = temp
	return b == n
*/
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------'

//Oppgave 2a
int maxOfTwo(int a, int b){
	if(a > b){
		cout << "A is greater than B" << endl;
		return a;
	}else{
		cout << "B is greater than A" << endl;
		return b;
	}
}
//Oppgave 2c
int fibonacci(int n){
	int a = 0;
	int b = 1;
	cout << "Fibonnaci numbers:\n";
	for(int x = 1; x < n+1; x++){
		cout << x << " " << b << endl;
		int temp = b;
		b += a;
		a = temp;
	}
	cout << "----\n";
	return b;
}
//Oppgave 2d)
int squareNumberSum(int n){
	int totalSum = 0;
	for(int i = 1; i <= n; i++){
		totalSum += i * i;
		cout << i * i << "\n";
	}
	cout << totalSum << "\n";
	return totalSum;
}

//Oppgave 2e)
void triangleNumbersBelow(int n){
	int acc = 1;
	int num = 2;
	string sep = "";
	cout << "Triangle numbers below " << n << ":" << sep << "\n";
	while(acc < n){
		cout << acc << "\n";
		acc += num;
		num += 1;
	}
	cout << "\n";
}

//Oppgave 2f)
bool isPrime(int n){
	for(int j = 2; j < n; j++){
		if((n % j) == 0){
			return 0;
		}
	}
	return 1;
}
//Oppgave 2g)
void naivePrimeNumberSearch(int n){
	for(int number = 2; number < n; number++){
		if(isPrime(number)){
			cout << number << " is a prime" << "\n";
		}
	}
}

//Oppgave 2h)
int findGreatestDivisor(int n){
	for(int divisor = (n - 1); divisor > 0; divisor--){
		if((n % divisor) == 0){
			return divisor;
		}
	}
}

// C++ programs start by executing the function main
int main()
{
	//Tester funksjoner
	//Oppgave 2b)
	//cout << "Oppgave a)\n";
	//cout << maxOfTwo(5,6) << "\n";
	//cout << maxOfTwo(6,5) << "\n";

	//Oppgave 2c)
	//cout << "Oppgave c)\n";
	//cout << fibonacci(10) << "\n";
	//cout << fibonacci(4) << "\n";


	//Oppgave 2d)
	//cout << "Oppgave d)\n";
	//cout << squareNumberSum(4) << "\n";
	//Returner da en 1, som i c++ betyr true
	//Endrer vi det til 54, får vi 0 som betyr false
	//cout << (squareNumberSum(5) == 55) << "\n";

	//Oppgave 2e)
	//cout << "Oppgave e)\n";
	//triangleNumbersBelow(11);
	//triangleNumbersBelow(40);


	//Oppgave 2f)
	//cout << "Oppgave f)\n";
	//Returner 1 som er true
	//cout << isPrime(5) << "\n";
	//Returner 0 som er false
	//cout << isPrime(6) << "\n";



	//Oppgave 2g)
	//cout << "Oppgave g)\n";
	//naivePrimeNumberSearch(5);
	//naivePrimeNumberSearch(8);
	/**
	 * Void funksjoner har ingen returnverdier,
	 * men ønsker vi å skrive ut til skjerm kan
	 * vi bare skrive dette i funksjonen og
	 * kalle på den sånn som over
	*/

	//Oppgave 2h)
	//cout << "Oppgave g)\n";
	//Returner 8
	//cout << findGreatestDivisor(16) << "\n";
	//Returner 7
	//cout << findGreatestDivisor(21) << "\n";
	

	keep_window_open();
}

//------------------------------------------------------------------------------
