#ifndef CREWMEMBER_HPP
#define CREWMEMBER_HPP

#include <string>

class CrewMember {
protected:
    std::string firstName;
    std::string lastName;
    float trainingScore;
    int missionAptitude;
    int id;
    static int nextID;

public:
    CrewMember(const std::string& first, const std::string& last, 
               float score, int aptitude);
    virtual ~CrewMember() = default;

    // Getters
    std::string getFirstName() const;
    std::string getLastName() const;
    float getTrainingScore() const;
    int getMissionAptitude() const;
    int getID() const;

    // Setters with validation
    void setTrainingScore(float score);
    void setMissionAptitude(int aptitude);

    // Virtual function for polymorphic output
    virtual void display() const = 0;

    // Friend comparison functions
    friend int compareTrainingScore(const CrewMember& a, const CrewMember& b);
    friend int compareMissionAptitude(const CrewMember& a, const CrewMember& b);
    friend int compareFirstName(const CrewMember& a, const CrewMember& b);
    friend int compareLastName(const CrewMember& a, const CrewMember& b);
};

#endif