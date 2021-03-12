#include "MeetingWindow.h"

static void cb_quit(Address, Address pw)  {
    reference_to<MeetingWindow>(pw).hide();
}

static void cb_new_person(Address,Address pw){
    reference_to<MeetingWindow>(pw).addPerson();
}
//Måtte legge til en ekstra metode for å få skrevet ting ut
static void cb_print_people(Address, Address pw){
    reference_to<MeetingWindow>(pw).printPeople();
}

MeetingWindow::MeetingWindow(Point xy, int w, int h, const string& title) : 
    Window(xy, w, h, title),
    quit_btn{Point{x_max()-70,0},70,20,"Quit",cb_quit},
    inbox_name{Point{pad_x,0},box_width,box_height,"Name"},
    inbox_email{Point{pad_x*3,0},box_width,box_height,"Email"},
    person_new_btn{Point{pad_x*4+20,10},button_width,button_height,"Submit",cb_new_person},
    print_person_btn{Point{pad_x*6+20,10},button_width,button_height,"Print",cb_print_people}
{
    attach(quit_btn);
    attach(inbox_name);
    attach(inbox_email);
    attach(person_new_btn);
    attach(print_person_btn);
}
//Destructor
MeetingWindow::~MeetingWindow(){
    for(auto* person : people){
        delete person;
    }

}

void MeetingWindow::addPerson(){
    if(inbox_email.get_string().length() > 0 && inbox_email.get_string().length() > 0){
        people.push_back(new Person(inbox_name.get_string(), inbox_email.get_string()));
        inbox_name.clear_value();
        inbox_email.clear_value();
    }else{
        cout << "Could not submit person" << endl;
    }
}

void MeetingWindow::printPeople(){
    for(auto person : people){
        cout << *person;
    }
}



