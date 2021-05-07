#include "generic.h"

template<typename T> 
T maximum(T lhs, T rhs){
    if(lhs == rhs){
        cout << "Elementene er like!" << endl;
    }else if(lhs > rhs){
        return lhs;
    }else if(rhs > lhs){
        return rhs;
    }
}
