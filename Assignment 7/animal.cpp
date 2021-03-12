#include "std_lib_facilities.h"
#include "animal.h"


//Oppgave 1a)
	/**
	 * Forskjell mellom private, public og protected
	 * private er bare tilgjengelig i klassen
	 * protected er bare tilgjengelig i klassen, arvede klasser og mappen
	 * public er tilgjengelig overalt
	 */

Animal::Animal(string name, int age) : name{name}, age{age}{}

string Animal::toString(){
    string value;
    value = "Animal: " + name + ", " + to_string(age) + "\n";
    return value;
}

Cat::Cat(string name, int age) : Animal(name, age){
    name = name;
    age = age;
};

string Cat::toString(){
    string value;
    value = "Cat: " + name + ", " + to_string(age) + "\n";
    return value;
}

Dog::Dog(string name, int age) : Animal(name, age){
    name = name;
    age = age;
};

string Dog::toString(){
    string value;
    value = "Dog: " + name + ", " + to_string(age) + "\n";
    return value;
}
