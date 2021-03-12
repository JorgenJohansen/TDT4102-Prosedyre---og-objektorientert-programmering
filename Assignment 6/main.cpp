//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "iostream"
#include "fstream"
#include "course.h"
#include "temps.h"


//------------------------------------------------------------------------------'
//Oppgave 1a)
//Funker
void readFromUser(){
	string input;
	cout << "Skriv 'quit' for å avslutte" << endl;
	cout << "Skriv inn et ord: ";
	cin >> input;
	ofstream file;
	file.open("userwords.txt");
	while(input != "quit"){
		file << input << endl;
		cout << "Skriv 'quit' for å avslutte" << endl;
		cout << "Skriv inn et ord: ";
		cin >> input;
	}
	file.close();
}
//Oppgave 1b)
//Funker
void lineNumber(){
	readFromUser();
	try{
		//Lager to variabler for lesing og skriving
		ifstream readFromFile;
		ofstream writeToFile;
		//Lager to variabler
		string txtFromFile = "";
		string txtToWrite = "";
		

		//Leser fra filen til en vektor
		vector<string> data;
		readFromFile.open("userwords.txt", ios_base::in);
		if(readFromFile.is_open()){
			while(readFromFile.good()){
				getline(readFromFile, txtFromFile);
				data.push_back(txtFromFile);
				//cout << txtFromFile
			}
			readFromFile.close();
		}

		/*
		//Skriver ut dataen
		for(string dat : data){
			cout << dat << endl;
		}
		*/
		//Legger tilbake dataen med linjenummer
		writeToFile.open("userwords.txt",ios_base::out);
		if(writeToFile.is_open()){
			for(unsigned int i = 0; i < data.size(); i++){
				txtToWrite = to_string(i+1) + ". " + data.at(i) + "\n";
				//cout << txtToWrite2;
				writeToFile << txtToWrite;
			}
			writeToFile.close();
		}
		//Lager en vektor som holder ordene
		//og skriver disse med linjetall tilbake i filen
		
	}catch(...){
		cout << "Kunne ikke finne filen" << endl;
	}
}

//Oppgave 2a)
//Funker
void generateCharStats(){
	//Lager en map med forekomster
	map<char,int> stats;
	//Lager en ny inputstream og åpner fila
	ifstream readFromFile;
	string line;
	readFromFile.open("grunnlov.txt", ios_base::in);
	if(readFromFile.is_open()){
		while(readFromFile.good()){
			getline(readFromFile, line);

			for(unsigned int i = 0; i < line.length(); i++){
				//teller bare for a-z
				if(tolower(line.at(i)) >= 'a' && tolower(line.at(i)) <= 'z'){
					//Hvis ikke den fins fra før i map
					//lager vi en ny nøkkel og setter verdien til 1
					//finner vi derimot nøkkelen inkrementerer vi verdien dens
					
					/*
					if(stats.find(tolower(line.at(i))) == stats.end()){
						stats[tolower(line.at(i))] = 1;
					}else{
						stats[tolower(line.at(i))] += 1;
					}
					*/
					//Funker også fint med bare denne ;)
					stats[tolower(line.at(i))] += 1;
					
				}
			}
			//går gjennom linja og teller forekomster
		}
		readFromFile.close();
	}

	//Skriver ut statistikken
	
	for(const auto &stat : stats){
		cout << stat.first << ": " << stat.second << endl;
	}

}


// C++ programs start by executing the function main
int main()
{
	//Fra tutorials:
	/*
	ofstream file;
	file.open("hello.txt", ios::app);

	vector<string> names;
	names.push_back("Jorgen");
	names.push_back("Kalle");
	names.push_back("Fredrik");

	for(string name: names){
		file << name << endl;
	}

	//file << "hey there";

	file.close();
	*/
	
	/*
	ofstream writeToFile;
	ofstream writeToFile2;
	ifstream readFromFile;
	string txtToWrite = "";
	string txtToWrite2 = "";
	string txtFromFile = "";

	writeToFile.open("test.txt",ios_base::out);
	if(writeToFile.is_open()){
		writeToFile << "Beginning og file \n";
		cout << "Enter data to write:";
		getline(cin, txtToWrite);
		writeToFile << txtToWrite;
		writeToFile.close();
	}

	vector<string> data;
	readFromFile.open("test.txt",ios_base::in);
	if(readFromFile.is_open()){
		while(readFromFile.good()){
			getline(readFromFile, txtFromFile);
			data.push_back(txtFromFile);
			//cout << txtFromFile
		}
		readFromFile.close();
	}

	for(string dat : data){
		cout << dat << endl;
	}

	writeToFile2.open("test.txt",ios_base::out);
	if(writeToFile2.is_open()){
		for(unsigned int i = 0; i < data.size(); i++){
			txtToWrite2 = to_string(i+1) + ". " + data.at(i) + "\n";
			//cout << txtToWrite2;
			writeToFile2 << txtToWrite2;
		}
		writeToFile2.close();
	}
	*/
	//String token:
	/*
	char line[] = "TDT4102: Prosedyre- og objektorientert programmering";
	vector<string> results;
	char* element = strtok(line, ":");
	while(element != NULL){
		results.push_back(element);
		cout << element << endl;
		element = strtok(NULL, ":");
	}
	*/


	
	


	//Tester oppgave 1.
	//readFromUser();
	//lineNumber();

	//Tester oppgave 2.
	//generateCharStats();
	
	//Tester oppgave 3.
	CourseCatalog courses{};
	//courses.addCourse(results[0],results[1]);
	//courses.addCourse("TDT4102","Prosedyre- og objektorientert programmering");
	//courses.addCourse("TDT4100","Objektorientert Programmering");
	//cout << courses;
	courses.addAndPrintThreeCourses();
	string line;
	for(const auto &course : courses.getCourses()){
        cout << course.first << endl;
        cout << course.second << endl;
        line = course.first + ": " + course.second ;
        cout << line << endl;
        //writeToFile << line;
    }
	string filename = "courses.txt";
	courses.writeToFile(filename);
	
	//Tester oppgave 4:
	/*
	Temps t{};
	t.readTemps("temperatures.txt");
	*/
	


	


	

	keep_window_open();
}

//------------------------------------------------------------------------------
