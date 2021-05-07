#include "dummy.h"

Dummy::Dummy(){
    num = new int{0};
}

Dummy::~Dummy(){
    delete num;
}

//Oppgave 3c)
//Kopi konstruktør
Dummy::Dummy(const Dummy& dummy){
    num = new int{0};
    *num = *dummy.num;
}

//Oppgave 3d)
//Overlagrer tilordnings operator
Dummy& Dummy::operator=(const Dummy& dummy){
    //Sjekker for selvjustering
    if(this != &dummy){
        *num = *(dummy.num);
    }
    return *this;


}