
//#include "std_lib_facilities.h"
#include "iostream"
using namespace std;
#include "matrix.h"
#include "dummy.h"

//Oppgave 1a)
void fillFibonacciNumbers(int result[], int length){
	// int num1 = 0;
	// int num2 = 1;
	result[0] = 0;
	result[1] = 1;
	for(int i = 2; i < length; i++){
		result[i] = result[i-1] + result[i-2];
		//cout << result[i] << endl;
	}
}

//Oppgave 1b)
void printArray(int arr[], int length){
	for(int i = 0; i < length; i++){
		cout << "Fibonacci tall " << i << ": " << arr[i] << endl;
	}
	
}

//oppgave 1c)
void createFibonacci(){
	//Spør bruker om antall
	int num;
	cout << "Hvor mange tall ønsker du å lage: ";
	cin >> num;
	//Generer en ny liste med 
	int* array = new int[num];
	//Fyller inn tall
	fillFibonacciNumbers(array,num);
	//Skriver ut lista
	printArray(array,num);
	//Frigir minne
	delete[] array;

}

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main()
{
	
	createFibonacci();
	//tutorial
	// int* array = new int[50];
	// int** array2d = new int*[50];

	// for(int i = 0; i < 50; i++){
	// 	array2d[i] = new int[50];
	// }
	
	//oppgave 2g)
	//Matrix matrix{10,10};
	//cout << matrix.getRows() << "\n";
	//cout << matrix.getColumns() << "\n";
	//matrix.set(9,9,4.0);
	//cout << matrix.get(9,9);

	//cout << matrix;

	//Oppgave 3:
	//dummyTest();


	//Oppgave 4:
	Matrix m{2,2};
	Matrix m2{2,2};
	Matrix m3{2,2};
	m2.set(1,1,3);
	m.set(1,1,4);
	m3 = m + m2;
	//cout << m;
	cout << m3;

	cin.get();
	
}

//------------------------------------------------------------------------------
