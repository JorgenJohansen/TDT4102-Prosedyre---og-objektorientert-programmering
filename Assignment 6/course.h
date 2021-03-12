#pragma once
#include "std_lib_facilities.h"

class CourseCatalog{
private:
    map<string, string> courses;
public:
    CourseCatalog();
    void addCourse(string code, string name);
    void removeCourse(string code);
    string getCourse(string code);
    friend ostream& operator<<(ostream& os, const CourseCatalog& c);
    map<string, string> getCourses();
    void addAndPrintThreeCourses();
    map<string,string> readFromFile(string filename);
    void writeToFile(string filename);
};