#ifndef CREW_SORT_HPP
#define CREW_SORT_HPP

#include <vector>
#include "human.hpp"
#include "alien.hpp"

// Single-field sorting functions (return sorted copies)
std::vector<Human> sortHumansByTrainingScore(const std::vector<Human>& humans);
std::vector<Human> sortHumansByMissionAptitude(const std::vector<Human>& humans);
std::vector<Human> sortHumansByFirstName(const std::vector<Human>& humans);
std::vector<Human> sortHumansByLastName(const std::vector<Human>& humans);

std::vector<Alien> sortAliensByTrainingScore(const std::vector<Alien>& aliens);
std::vector<Alien> sortAliensByMissionAptitude(const std::vector<Alien>& aliens);
std::vector<Alien> sortAliensByFirstName(const std::vector<Alien>& aliens);
std::vector<Alien> sortAliensByLastName(const std::vector<Alien>& aliens);

// Overall multi-field sorting
std::vector<Human> sortHumansOverall(const std::vector<Human>& humans);
std::vector<Alien> sortAliensOverall(const std::vector<Alien>& aliens);

#endif