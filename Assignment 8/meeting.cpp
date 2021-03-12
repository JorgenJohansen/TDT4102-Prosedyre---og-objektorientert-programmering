#include "meeting.h"
//Oppgave 3a)
ostream& operator<<(ostream& os, const Campus c){
    
    os << campusMap[c];
    return os;
}

//Oppgave 3e)
Meeting::Meeting(int day, int startTime, int endTime, Campus location, string subject, const Person* leader) :
    day{day}, startTime{startTime}, endTime{endTime}, location{location}, subject{subject}, leader{leader}{}

//Oppgave 3d)
Meeting::~Meeting(){
    for(auto meeting : meetings){
        delete meeting;
    }
}


int Meeting::getDay() const {
    return day;
}

int Meeting::getStartTime() const {
    return startTime;
}

int Meeting::getEndTime() const {
    return endTime;
}

Campus Meeting::getLocation() const {
    return location;
}

string Meeting::getSubject() const {
    return subject;
}

const Person* Meeting::getLeader() const {
    return leader;
}

//Oppgave 3c)
void Meeting::addParticipants(const Person* participant){
    participants.insert(participant);
}

//Oppgave 3g)
vector<string> Meeting::getParticipantList() const{
    vector<string> participantList;
    for(auto participant : participants){
        participantList.push_back(participant->getName());
    }
    return participantList;
}

//Oppgave 3h)
ostream& operator<<(ostream& os, const Meeting* meeting){
    os << "Tema: " << meeting->getSubject() << ", sted: " << meeting->getLocation() 
    << ", starttid: " << meeting->getStartTime() << ", sluttid: " << meeting->getEndTime() 
    << ", navn på leder: " << meeting->getLeader() << endl;
    meeting->getParticipantList().size();

    for(unsigned int i = 0; i < meeting->getParticipantList().size(); i++){
        os << "Deltaker: " << meeting->getParticipantList()[i] << endl;
    }
    return os;
}

//Spør studass om denne
//Oppgave 3i)
vector<const Person*> Meeting::findPotentialCoDriving(){
    vector<const Person*> potentialDrivers;
    //Looper gjennom set-et meetings
    for(auto meeting : meetings){
        //Sjekker om location, dag, startpunkt, sluttpunkt er det samme
        if(meeting->getLocation() == location && 
        meeting->getDay() == day &&
        abs(meeting->getStartTime() - startTime) < 1 &&
        abs(meeting->getEndTime() - endTime) < 1
        ){
            //Looper gjennom deltagerne i lista og pusher de til vektoren
            for(auto people : meeting->participants){
                potentialDrivers.push_back(people);
            }
        }
    }
    return potentialDrivers;
}





