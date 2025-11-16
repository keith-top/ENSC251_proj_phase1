#include "crewmember.hpp"
#include <stdexcept>

int CrewMember::nextID = 25220000;

CrewMember::CrewMember(const std::string& first, const std::string& last, 
                       float score, int aptitude)
    : firstName(first), lastName(last), trainingScore(score), 
      missionAptitude(aptitude), id(nextID++) {
    
    setTrainingScore(score);
    setMissionAptitude(aptitude);
}

std::string CrewMember::getFirstName() const { return firstName; }
std::string CrewMember::getLastName() const { return lastName; }
float CrewMember::getTrainingScore() const { return trainingScore; }
int CrewMember::getMissionAptitude() const { return missionAptitude; }
int CrewMember::getID() const { return id; }

void CrewMember::setTrainingScore(float score) {
    if (score < 0.0f || score > 4.3f) {
        throw std::invalid_argument("Training score must be between 0.0 and 4.3");
    }
    trainingScore = score;
}

void CrewMember::setMissionAptitude(int aptitude) {
    if (aptitude < 0 || aptitude > 100) {
        throw std::invalid_argument("Mission aptitude must be between 0 and 100");
    }
    missionAptitude = aptitude;
}

// Friend comparison functions
int compareTrainingScore(const CrewMember& a, const CrewMember& b) {
    if (a.trainingScore > b.trainingScore) return 1;
    if (a.trainingScore < b.trainingScore) return -1;
    return 0;
}

int compareMissionAptitude(const CrewMember& a, const CrewMember& b) {
    if (a.missionAptitude > b.missionAptitude) return 1;
    if (a.missionAptitude < b.missionAptitude) return -1;
    return 0;
}

int compareFirstName(const CrewMember& a, const CrewMember& b) {
    if (a.firstName < b.firstName) return -1;
    if (a.firstName > b.firstName) return 1;
    return 0;
}

int compareLastName(const CrewMember& a, const CrewMember& b) {
    if (a.lastName < b.lastName) return -1;
    if (a.lastName > b.lastName) return 1;
    return 0;
}