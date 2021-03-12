#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "faces.h"


//Oppgave 5a)
SmileyFace::SmileyFace(Point c, int r) : EmptyFace(c,r), smileyMouth{c,40,20,180,0}{
    
}

void SmileyFace::attach_to(Graph_lib::Window& win){
    EmptyFace::attach_to(win);
    win.attach(smileyMouth);
}

//Oppgave 5b)
//Jeg valgte å arve fra emptyFace siden munnen er annerledes
//i sadface
SadFace::SadFace(Point c, int r) : EmptyFace(c,r), sadly{Point{c.x,c.y+20}, 40,20,360,180}{

}

void SadFace::attach_to(Graph_lib::Window& win){
    EmptyFace::attach_to(win);
    win.attach(sadly);
}

//Oppgave 5c)
AngryFace::AngryFace(Point c, int r) : EmptyFace(c,r), angryMouth{Point{c.x,c.y+20}, 40,20,360,160}, leftEyeCross{Point{c.x-20,c.y-20},20,5,180,0}, rightEyeCross{Point{c.x+20,c.y-20},20,5,180,0}{

}

void AngryFace::attach_to(Graph_lib::Window& win){
    EmptyFace::attach_to(win);
    win.attach(angryMouth);
    win.attach(leftEyeCross);
    win.attach(rightEyeCross);
}
//Oppgave 5d)
WinkyFace::WinkyFace(Point c, int r) : Face(c,r), smileyMouth{c,40,20,180,0}, leftEye{{c.x-12,c.y-12},7}, winkyRightEye{Point{c.x+12,c.y-10},16,12,360,180}{
    leftEye.set_fill_color(Color::black);
}

void WinkyFace::attach_to(Graph_lib::Window& win){
    Face::attach_to(win);
    win.attach(smileyMouth);
    win.attach(leftEye);
    win.attach(winkyRightEye);
}

//Oppgave 5e)
SurprisedFace::SurprisedFace(Point c, int r) : EmptyFace(c,r), surpriseMouth{Point{c.x,c.y+20},40,20,360,0}{

}

void SurprisedFace::attach_to(Graph_lib::Window& win){
    EmptyFace::attach_to(win);
    win.attach(surpriseMouth);
}
