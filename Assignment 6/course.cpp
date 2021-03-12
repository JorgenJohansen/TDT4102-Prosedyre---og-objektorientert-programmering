#include "std_lib_facilities.h"
#include "course.h"

CourseCatalog::CourseCatalog(){
    map<string, string> courses;
}

void CourseCatalog::addCourse(string code, string name){
    courses[code] = name;
}

void CourseCatalog::removeCourse(string code){
    courses.erase(code);
}
void CourseCatalog::addAndPrintThreeCourses(){
    addCourse("TDT4110","Informasjonsteknologi grunnkurs");
    addCourse("TDT4102","Prosedyre- og objektorientert programmering");
    //courses["TDT4102"] = "C++";
    addCourse("TMA4100", "Matematikk 1");
    //cout << courses;

}

map<string, string> CourseCatalog::readFromFile(string filename){
    ifstream readFromFile;
    readFromFile.open(filename,ios_base::in);
    string lineFromFile;
    vector<string> data;
    map<string,string> courseMap;

    //TODO: få convertert hver linje til elementer i map'en
    if(readFromFile.is_open()){
        while(readFromFile.good()){
            getline(readFromFile, lineFromFile);
            data.push_back(lineFromFile);
        }
        readFromFile.close();
    }

    //WIP: kan kanskje gjøres operator overloading?
    string code;
    string name;
    for(unsigned int i = 0; i < data.size(); i++){
        stringstream ss = static_cast<stringstream>(data[i]);
        getline(ss, code, ':');
        getline(ss, name, ':');
        courseMap[code] = name;

        //char line[] = data[i];
        //vector<string> results;
        //char* element = strtok(line, ":");
        //while(element != NULL){
        //    results.push_back(element);
        //    element = strtok(NULL, ":");
        //}
        
    }
    
    return courseMap;

}

void CourseCatalog::writeToFile(string filename){
    cout << "hello!" << endl;
    ofstream writeToFile{filename};
    string line;
    //writeToFile.open(filename, ios_base::out);
    /*
    if(writeToFile.is_open()){
        cout << "hello again" << endl;
        for(const auto &course : courses){
            cout << course.first << endl;
            cout << course.second << endl;
            line = course.first + ": " + course.second;
            cout << line << endl;
            writeToFile << line;
        }
        writeToFile.close();
    }
    */
    if(!writeToFile){
        cerr << "error" << endl;
    }
    
    for(const auto &course : courses){
        line = course.first + ": " + course.second + "\n";
        writeToFile << line;
    }
    writeToFile.close();
}

string CourseCatalog::getCourse(string code){
    return courses[code];
}

//Brukes ikke

map<string, string> CourseCatalog::getCourses(){
    return courses;
}

//& er en string referanse
ostream& operator<<(ostream& os, const CourseCatalog& c){
    for(const auto &course : c.courses){
        os << course.first << ": " << course.second << endl;
    } 
    return os;
}