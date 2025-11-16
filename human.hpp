#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "crewmember.hpp"
#include <iostream>

class Human : public CrewMember {
private:
    std::string homeSector;

public:
    Human(const std::string& first, const std::string& last, 
          float score, int aptitude, const std::string& sector);
    
    std::string getHomeSector() const;
    void setHomeSector(const std::string& sector);
    
    void display() const override;
    
    // Overload output operator
    friend std::ostream& operator<<(std::ostream& os, const Human& human);
};

#endif