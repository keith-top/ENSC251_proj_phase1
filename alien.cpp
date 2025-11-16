#include "alien.hpp"
#include <iomanip>

Alien::Alien(const std::string& first, const std::string& last, 
             float score, int aptitude, const std::string& world,
             int signal, int cognitive, int empathic, int resistance)
    : CrewMember(first, last, score, aptitude), homeworld(world),
      telepathicTest(signal, cognitive, empathic, resistance) {}

std::string Alien::getHomeworld() const { return homeworld; }

void Alien::setHomeworld(const std::string& world) {
    homeworld = world;
}

TelepathicLinkTest Alien::getTelepathicTest() const {
    return telepathicTest;
}

void Alien::display() const {
    std::cout << *this;
}

std::ostream& operator<<(std::ostream& os, const Alien& alien) {
    os << "Alien Crew Member:\n"
       << "  ID: " << alien.id << "\n"
       << "  Name: " << alien.firstName << " " << alien.lastName << "\n"
       << "  Homeworld: " << alien.homeworld << "\n"
       << "  Training Score: " << std::fixed << std::setprecision(1) << alien.trainingScore << "\n"
       << "  Mission Aptitude: " << alien.missionAptitude << "\n"
       << "  Telepathic Test Total: " << alien.telepathicTest.getTotal() << "\n";
    return os;
}