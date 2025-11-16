//file_parser to read data from human and alien crew txt files

#include "human.hpp"
#include "alien.hpp"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

std::vector<Human> parseHumanFile(const std::string& filename) {
    std::vector<Human> humans;
    std::ifstream file(filename);
    std::string line;
    
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return humans;
    }
    
    // Skip header
    std::getline(file, line);
    
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string firstName, lastName, sector;
        float trainingScore;
        int missionAptitude;
        
        if (ss >> firstName >> lastName >> sector >> trainingScore >> missionAptitude) {
            try {
                humans.emplace_back(firstName, lastName, trainingScore, missionAptitude, sector);
            } catch (const std::exception& e) {
                std::cerr << "Warning: Skipping invalid human data: " << line << std::endl;
                std::cerr << "Error: " << e.what() << std::endl;
            }
        } else {
            std::cerr << "Warning: Skipping malformed line in human file: " << line << std::endl;
        }
    }
    
    file.close();
    return humans;
}

std::vector<Alien> parseAlienFile(const std::string& filename) {
    std::vector<Alien> aliens;
    std::ifstream file(filename);
    std::string line;
    
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return aliens;
    }
    
    // Skip header
    std::getline(file, line);
    
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string firstName, lastName, homeworld;
        float trainingScore;
        int missionAptitude, signalStrength, cognitiveLink, empathicOverlay, cognitiveResistance, total;
        
        if (ss >> firstName >> lastName >> homeworld >> trainingScore >> missionAptitude
               >> signalStrength >> cognitiveLink >> empathicOverlay >> cognitiveResistance >> total) {
            try {
                aliens.emplace_back(firstName, lastName, trainingScore, missionAptitude, homeworld,
                                   signalStrength, cognitiveLink, empathicOverlay, cognitiveResistance);
            } catch (const std::exception& e) {
                std::cerr << "Warning: Skipping invalid alien data: " << line << std::endl;
                std::cerr << "Error: " << e.what() << std::endl;
            }
        } else {
            std::cerr << "Warning: Skipping malformed line in alien file: " << line << std::endl;
        }
    }
    
    file.close();
    return aliens;
}