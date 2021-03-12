#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "face.h"
//faceBase må ha verdier for å kunne finnes
Face::Face(Point c, int r) : faceBase{c,r} {
    faceBase.set_fill_color(Color::yellow);
}

void Face::attach_to(Graph_lib::Window& win){
    win.attach(faceBase);
}

