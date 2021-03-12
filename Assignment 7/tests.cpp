#include "std_lib_facilities.h"
#include "animal.h"
#include "tests.h"

void testAnimal(){
    Animal animal1{"Brage", 10};
    Dog dog1{"Sandra", 10};
    Cat cat1{"Ebba", 17};

    

    string nameAndAgeAnimal = animal1.toString();
    cout << nameAndAgeAnimal;
    string nameAndAgeDog = dog1.toString();
    cout << nameAndAgeDog;
    string nameAndAgeCat = cat1.toString();
    cout << nameAndAgeCat;
}
