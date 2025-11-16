#ifndef ALIEN_HPP
#define ALIEN_HPP

#include "crewmember.hpp"
#include "telepathiclinktest.hpp"
#include <iostream>

class Alien : public CrewMember {
private:
    std::string homeworld;
    TelepathicLinkTest telepathicTest;

public:
    Alien(const std::string& first, const std::string& last, 
          float score, int aptitude, const std::string& world,
          int signal, int cognitive, int empathic, int resistance);
    
    std::string getHomeworld() const;
    void setHomeworld(const std::string& world);
    TelepathicLinkTest getTelepathicTest() const;
    
    void display() const override;
    
    // Overload output operator
    friend std::ostream& operator<<(std::ostream& os, const Alien& alien);
};

#endif