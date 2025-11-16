#include "crew_sort.hpp"
#include <algorithm>

// Custom sorting algorithms (no std::sort)

// Bubble sort implementation for vectors
template<typename T>
std::vector<T> bubbleSort(const std::vector<T>& vec, 
                         bool (*compare)(const T&, const T&)) {
    std::vector<T> sorted = vec;
    int n = sorted.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compare(sorted[j + 1], sorted[j])) {
                std::swap(sorted[j], sorted[j + 1]);
            }
        }
    }
    return sorted;
}

// Comparison functions for Humans
bool compareHumanTrainingScore(const Human& a, const Human& b) {
    return compareTrainingScore(a, b) > 0;
}

bool compareHumanMissionAptitude(const Human& a, const Human& b) {
    return compareMissionAptitude(a, b) > 0;
}

bool compareHumanFirstName(const Human& a, const Human& b) {
    return compareFirstName(a, b) < 0;
}

bool compareHumanLastName(const Human& a, const Human& b) {
    return compareLastName(a, b) < 0;
}

// Comparison functions for Aliens
bool compareAlienTrainingScore(const Alien& a, const Alien& b) {
    return compareTrainingScore(a, b) > 0;
}

bool compareAlienMissionAptitude(const Alien& a, const Alien& b) {
    return compareMissionAptitude(a, b) > 0;
}

bool compareAlienFirstName(const Alien& a, const Alien& b) {
    return compareFirstName(a, b) < 0;
}

bool compareAlienLastName(const Alien& a, const Alien& b) {
    return compareLastName(a, b) < 0;
}

// Human sorting implementations
std::vector<Human> sortHumansByTrainingScore(const std::vector<Human>& humans) {
    return bubbleSort(humans, compareHumanTrainingScore);
}

std::vector<Human> sortHumansByMissionAptitude(const std::vector<Human>& humans) {
    return bubbleSort(humans, compareHumanMissionAptitude);
}

std::vector<Human> sortHumansByFirstName(const std::vector<Human>& humans) {
    return bubbleSort(humans, compareHumanFirstName);
}

std::vector<Human> sortHumansByLastName(const std::vector<Human>& humans) {
    return bubbleSort(humans, compareHumanLastName);
}

// Alien sorting implementations
std::vector<Alien> sortAliensByTrainingScore(const std::vector<Alien>& aliens) {
    return bubbleSort(aliens, compareAlienTrainingScore);
}

std::vector<Alien> sortAliensByMissionAptitude(const std::vector<Alien>& aliens) {
    return bubbleSort(aliens, compareAlienMissionAptitude);
}

std::vector<Alien> sortAliensByFirstName(const std::vector<Alien>& aliens) {
    return bubbleSort(aliens, compareAlienFirstName);
}

std::vector<Alien> sortAliensByLastName(const std::vector<Alien>& aliens) {
    return bubbleSort(aliens, compareAlienLastName);
}

// Overall multi-field sorting with custom comparison
bool compareHumanOverall(const Human& a, const Human& b) {
    if (a.getMissionAptitude() != b.getMissionAptitude())
        return a.getMissionAptitude() > b.getMissionAptitude();
    if (a.getTrainingScore() != b.getTrainingScore())
        return a.getTrainingScore() > b.getTrainingScore();
    return a.getHomeSector() < b.getHomeSector();
}

bool compareAlienOverall(const Alien& a, const Alien& b) {
    if (a.getMissionAptitude() != b.getMissionAptitude())
        return a.getMissionAptitude() > b.getMissionAptitude();
    if (a.getTrainingScore() != b.getTrainingScore())
        return a.getTrainingScore() > b.getTrainingScore();
    return a.getHomeworld() < b.getHomeworld();
}

std::vector<Human> sortHumansOverall(const std::vector<Human>& humans) {
    return bubbleSort(humans, compareHumanOverall);
}

std::vector<Alien> sortAliensOverall(const std::vector<Alien>& aliens) {
    std::vector<Alien> filtered;
    for (const auto& alien : aliens) {
        if (alien.getTelepathicTest().getTotal() >= 15) {
            filtered.push_back(alien);
        }
    }
    return bubbleSort(filtered, compareAlienOverall);
}