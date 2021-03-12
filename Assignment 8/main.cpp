//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "person.h"
#include "car.h"
#include "meeting.h"
#include "MeetingWindow.h"



//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main()
{

	//Tester oppgave 2e)
	Car car1{5};
	Person p1{"Jorgen", "jorgen@hotmail.com"};
	//cout << p1;
	
	Meeting meeting{1,12,14, Campus::Trondheim,"Cpp", &p1};
	//cout << Campus;
	//cout << meeting;
	//Tester oppgave 4-5
	MeetingWindow window{Point{0,0},w_width,w_height,"Meetings"};
	gui_main();
	//window.printPeople();

	keep_window_open();
}

//------------------------------------------------------------------------------
