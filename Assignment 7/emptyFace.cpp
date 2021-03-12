#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "face.h"
#include "emptyFace.h"


EmptyFace::EmptyFace(Point c, int r) : Face(c,r) , leftEye{{c.x-12,c.y-12},7}, rightEye{{c.x+12,c.y-12},7} {
    leftEye.set_fill_color(Color::black);
    rightEye.set_fill_color(Color::black);
}

void EmptyFace::attach_to(Graph_lib::Window& win){
    Face::attach_to(win);
    win.attach(leftEye);
    win.attach(rightEye);
}