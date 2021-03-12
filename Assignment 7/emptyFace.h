#pragma once
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "face.h"

class EmptyFace : public Face {
protected:
    Circle leftEye;
    Circle rightEye;
    int eyeRadius = 7;
    int eyeVerticalOffset = 12;
    int eyeHorisontalOffset = 20;

public:
    void attach_to(Graph_lib::Window& win) override;
    EmptyFace(Point c, int r);

};