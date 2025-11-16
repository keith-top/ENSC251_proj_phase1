#include <iostream>
#include <vector>
#include <limits>
#include "human.hpp"
#include "alien.hpp"
#include "crew_sort.hpp"
#include "file_parser.hpp"
#include "tests.hpp"

void displayMenu() {
    std::cout << "\n=== Interplanetary Alliance Recruitment System ===\n";
    std::cout << "1. Single-field sort - Humans\n";
    std::cout << "2. Single-field sort - Aliens\n";
    std::cout << "3. Overall sort - Humans\n";
    std::cout << "4. Overall sort - Aliens\n";
    std::cout << "5. Exit\n";
    std::cout << "6. Test program\n";
    std::cout << "Enter your choice (1-6): ";
}

void displaySingleFieldMenu(const std::string& type) {
    std::cout << "\n=== " << type << " Single-field Sort ===\n";
    std::cout << "1. Sort by Training Score (High to Low)\n";
    std::cout << "2. Sort by Mission Aptitude (High to Low)\n";
    std::cout << "3. Sort by First Name (A to Z)\n";
    std::cout << "4. Sort by Last Name (A to Z)\n";
    std::cout << "Enter your choice (1-4): ";
}

void displayResults(const std::vector<Human>& humans) {
    std::cout << "\n=== Sorted Human Crew Members ===\n";
    for (const auto& human : humans) {
        std::cout << human << std::endl;
    }
}

void displayResults(const std::vector<Alien>& aliens) {
    std::cout << "\n=== Sorted Alien Crew Members ===\n";
    for (const auto& alien : aliens) {
        std::cout << alien << std::endl;
    }
}

int main() {
    std::vector<Human> humans = parseHumanFile("human-crew.txt");
    std::vector<Alien> aliens = parseAlienFile("alien-crew.txt");
    
    std::cout << "Loaded " << humans.size() << " human crew members.\n";
    std::cout << "Loaded " << aliens.size() << " alien crew members.\n";
    
    int choice;
    bool exitProgram = false;
    
    while (!exitProgram) {
        displayMenu();
        std::cin >> choice;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number 1-6.\n";
            continue;
        }
        
        switch (choice) {
            case 1: { // Single-field sort Humans
                int subChoice;
                displaySingleFieldMenu("Human");
                std::cin >> subChoice;
                
                std::vector<Human> sortedHumans;
                switch (subChoice) {
                    case 1:
                        sortedHumans = sortHumansByTrainingScore(humans);
                        break;
                    case 2:
                        sortedHumans = sortHumansByMissionAptitude(humans);
                        break;
                    case 3:
                        sortedHumans = sortHumansByFirstName(humans);
                        break;
                    case 4:
                        sortedHumans = sortHumansByLastName(humans);
                        break;
                    default:
                        std::cout << "Invalid choice.\n";
                        continue;
                }
                displayResults(sortedHumans);
                break;
            }
            
            case 2: { // Single-field sort Aliens
                int subChoice;
                displaySingleFieldMenu("Alien");
                std::cin >> subChoice;
                
                std::vector<Alien> sortedAliens;
                switch (subChoice) {
                    case 1:
                        sortedAliens = sortAliensByTrainingScore(aliens);
                        break;
                    case 2:
                        sortedAliens = sortAliensByMissionAptitude(aliens);
                        break;
                    case 3:
                        sortedAliens = sortAliensByFirstName(aliens);
                        break;
                    case 4:
                        sortedAliens = sortAliensByLastName(aliens);
                        break;
                    default:
                        std::cout << "Invalid choice.\n";
                        continue;
                }
                displayResults(sortedAliens);
                break;
            }
            
            case 3: { // Overall sort Humans
                std::vector<Human> sortedHumans = sortHumansOverall(humans);
                displayResults(sortedHumans);
                break;
            }
            
            case 4: { // Overall sort Aliens
                std::vector<Alien> sortedAliens = sortAliensOverall(aliens);
                std::cout << "Note: Aliens with TelepathicLinkTest total < 15 are excluded.\n";
                displayResults(sortedAliens);
                break;
            }
            
            case 5:
                exitProgram = true;
                std::cout << "Thank you for using the Interplanetary Alliance Recruitment System!\n";
                break;

            case 6: { //run tests
                vector<Human> humans;
                for (int i = 0; i < 100; ++i) { //generates random humans for testing
                    humans.push_back(createRandomHuman());
                }
                vector<Alien> aliens;
                for (int i = 0; i < 100; ++i) { //generates random aliens for testing
                    aliens.push_back(createRandomAlien());
                }
                // Run tests
                std::cout << "Running tests for human sorting...\n";
                testFirstNameSort(humans);
                testLastNameSort(humans);
                testTrainingScoreSort(humans);
                testMissionAptitudeSort(humans);
                testOverallSort(humans);

                std::cout <<"running tests for alien sorting...\n";
                testFirstNameSortAlien(aliens);
                testLastNameSortAlien(aliens);
                testTrainingScoreSortAlien(aliens);
                testMissionAptitudeSortAlien(aliens);
                testOverallSortAlien(aliens);

                testInvalidInputs();
                break;
                
            }
                
            default:
                std::cout << "Invalid choice. Please enter a number 1-6.\n";
                break;
        }
    }
    
    return 0;
}
