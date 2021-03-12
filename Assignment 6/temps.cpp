#include "std_lib_facilities.h"
#include "temps.h"

Temps::Temps(){
    min = 0;
    max = 0;
}

Temps::Temps(double min, double max){
    min = min;
    max = max;
}



vector<Temps> Temps::readTemps(string filename){
    ifstream readFromFile;
    readFromFile.open(filename);
    vector<Temps> temps;
    vector<string> data;
    string line;
    Temps t{};
    //Henter ut dataen fra fila
    //og lagrer hver linje i en vektor
    if(readFromFile.is_open()){
        while(readFromFile.good()){
            getline(readFromFile, line);
            data.push_back(line);

        }
        readFromFile.close();
    }

    for(unsigned int i = 0; i < data.size(); i++){
        data[i] >> t;
    }

    return temps;



}

void Temps::tempStats(vector<Temps> temps){
    double min = temps[0].min;
    double max = temps[0].max;
    int minIndex = 0;
    int maxIndex = 0;
    //Looper gjennom for å finne min og indexen det er på
    for(unsigned int i = 0; i < temps.size(); i++){
        if(temps[i+1].min < temps[i].min){
            min = temps[i+1].min;
            minIndex = i+1;
        }
    }
    
    //Looper gjennom for å finne min og indexen det er på
    for(unsigned int i = 0; i < temps.size(); i++){
        if(temps[i+1].max > temps[i].max){
            max = temps[i+1].max;
            maxIndex = i+1;
        }
    }
    //Skriver ut verdiene
    cout << "Minimum temperatur var: " << min << ", på index " << minIndex << endl
        << "Maksimum temperatur var: " << max << ", på index" << maxIndex << endl;
}

istream& operator>>(istream& input, Temps& t){
    input >> t.min >> t.max;
    return input;
}