#pragma once
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "emptyFace.h"
#include "face.h"

class SmileyFace : public EmptyFace {
protected:
    Arc smileyMouth;
public:
    SmileyFace(Point c, int r);
    void attach_to(Graph_lib::Window& win) override;
};

class SadFace : public EmptyFace {
protected:
    Arc sadly;
public:
    SadFace(Point c, int r);
    void attach_to(Graph_lib::Window& win) override;
};

class AngryFace : public EmptyFace {
protected:
    Arc angryMouth;
    Arc leftEyeCross;
    Arc rightEyeCross;
    
public:
    AngryFace(Point c, int r);
    void attach_to(Graph_lib::Window& win) override;
};

class WinkyFace : public Face {
protected:
    Arc smileyMouth;
    Circle leftEye;
    Arc winkyRightEye;
public:
    WinkyFace(Point c, int r);
    void attach_to(Graph_lib::Window& win) override;
};

class SurprisedFace : public EmptyFace {
protected:
    Arc surpriseMouth;
public:
    SurprisedFace(Point c, int r);
    void attach_to(Graph_lib::Window& win) override;
};

