#pragma once
#include "std_lib_facilities.h"
#include "person.h"
//Oppgave 3a)
enum class Campus{Trondheim, Aalesund, Gjovik};
map<Campus, string> campusMap{{Campus::Trondheim,"Trondheim"},{Campus::Aalesund,"Aalesund"},{Campus::Gjovik,"Gjovik"}};

//Oppgave 3B)
class Meeting {
private:
    int day;
    int startTime;
    int endTime;
    Campus location;
    string subject;
    const Person* leader;
    set<const Person*> participants;
    //Oppgave
    static inline set<const Meeting*> meetings{};
public:
    int getDay() const;
    int getStartTime() const;
    int getEndTime() const;
    Campus getLocation() const;
    string getSubject() const;
    const Person* getLeader() const;
    void addParticipants(const Person* participant);
    Meeting(int day, int startTime, int endTime, Campus location, string subject, const Person* leader);
    ~Meeting();
    vector<string> getParticipantList() const;
    vector<const Person*> findPotentialCoDriving();

};