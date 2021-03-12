#pragma once
#include "std_lib_facilities.h"
#include "Graph.h"
#include "Gui.h"
#include "person.h"
using namespace Graph_lib;
static constexpr int w_width = 600;
static constexpr int w_height = 600;

static constexpr int button_width = 70;
static constexpr int button_height = 20;

static constexpr int box_width = 80;
static constexpr int box_height = 30;

static constexpr int pad_x = 70;
static constexpr int pad_y = 140;





class MeetingWindow : public Window {
private:
    
    Button quit_btn;
    Button person_new_btn;
    Button print_person_btn;
    In_box inbox_name;
    In_box inbox_email;
    vector<Person*> people;
    
    
public:
    MeetingWindow(Point xy, int w, int h, const string& title);
    ~MeetingWindow();
    void addPerson();
    void printPeople();
};