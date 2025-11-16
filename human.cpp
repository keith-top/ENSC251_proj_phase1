#include "human.hpp"
#include <iomanip>

Human::Human(const std::string& first, const std::string& last, 
             float score, int aptitude, const std::string& sector)
    : CrewMember(first, last, score, aptitude), homeSector(sector) {}

std::string Human::getHomeSector() const { return homeSector; }

void Human::setHomeSector(const std::string& sector) {
    homeSector = sector;
}

void Human::display() const {
    std::cout << *this;
}

std::ostream& operator<<(std::ostream& os, const Human& human) {
    os << "Human Crew Member:\n"
       << "  ID: " << human.id << "\n"
       << "  Name: " << human.firstName << " " << human.lastName << "\n"
       << "  Home Sector: " << human.homeSector << "\n"
       << "  Training Score: " << std::fixed << std::setprecision(1) << human.trainingScore << "\n"
       << "  Mission Aptitude: " << human.missionAptitude << "\n";
    return os;
}