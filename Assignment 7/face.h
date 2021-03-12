#pragma once
#include "Simple_window.h"
#include "Emoji.h"


class Face : public Emoji {
protected:
    Circle faceBase;
public:
    virtual void attach_to(Graph_lib::Window& win) override = 0;
    Face(Point c, int r);
    
};