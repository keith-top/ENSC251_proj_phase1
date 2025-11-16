#include <iostream>
#include <vector>
#include <limits>
#include <ctime>
#include <unistd.h>
#include "human.hpp"
#include "alien.hpp"
#include "crew_sort.hpp"
#include "file_parser.hpp"
using namespace std;

string generateRandomString(const int length) { //generates a random string of letters given a length
    static const char alphabet[] =
        "abcdefghijklmnopqrstuvwxyz";
    string randName;
    randName.reserve(length);

    for (int i = 0; i < length; ++i) {
        randName += alphabet[rand() % (sizeof(alphabet) - 1)];
    }
    
    return randName;
}

int generateRandomNum(int min, int max) { //generates a random integer between min and max
    return rand() % (max - min + 1) + min;
}

int generateRandomFloat(float min, float max) { //generates a random float between min and max
    return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

Human createRandomHuman() { //generates a random human
    return Human(generateRandomString(5),
    generateRandomString(5),
    generateRandomFloat(0, 4.2),
    generateRandomNum(0, 100),
    generateRandomString(4));
}


Human createRandomInvalidHuman() { //creates a human with potentially invalid training score or mission aptitude
    float trainingScore;
    int missionAptitude;
    if (generateRandomNum(0,1) == 0){ //generate invalid training score, negaive if randNum = 0, or over 4.3 if randNum = 1
        trainingScore = generateRandomFloat(-5, 0); //generate invalid training score below 0
    }
    else{
        trainingScore = generateRandomFloat(4.4, 10); //generate invalid training score above 4.3
    }

    if (generateRandomNum(0,1) == 0){ //generate invalid mission Aptitude, negaive if randNum = 0, or over 100 if randNum = 1
        missionAptitude = generateRandomNum(-50, 0); //generate invalid mission aptitude below 0
    }
    else{
        missionAptitude = generateRandomNum(101, 150); //generate invalid mission aptitude above 100
    }
    return Human(generateRandomString(5), generateRandomString(5), trainingScore, missionAptitude, generateRandomString(4));
}

Alien createRandomAlien() { //generates a random alien
    return Alien(generateRandomString(5),
    generateRandomString(5),
    generateRandomFloat(0, 4.2),
    generateRandomNum(0, 100),
    generateRandomString(4),
    generateRandomNum(0, 9),
    generateRandomNum(0, 9),
    generateRandomNum(0, 9),
    generateRandomNum(0, 9));
}

Alien createRandomInvalidAlien() { //creates an alien with potentially invalid training score or mission aptitude
    float trainingScore;
    int missionAptitude;
    if (generateRandomNum(0,1) == 0){ //generate invalid training score, negaive if randNum = 0, or over 4.3 if randNum = 1
        trainingScore = generateRandomFloat(-5, 0); //generate invalid training score below 0
    }
    else{
        trainingScore = generateRandomFloat(4.4, 10); //generate invalid training score above 4.3
    }

    if (generateRandomNum(0,1) == 0){ //generate invalid mission Aptitude, negaive if randNum = 0, or over 100 if randNum = 1
        missionAptitude = generateRandomNum(-50, 0); //generate invalid mission aptitude below 0
    }
    else{
        missionAptitude = generateRandomNum(101, 150); //generate invalid mission aptitude above 100
    }
    return Alien(generateRandomString(5), generateRandomString(5), trainingScore, missionAptitude,
    generateRandomString(4), generateRandomNum(0, 9), generateRandomNum(0, 9),
    generateRandomNum(0, 9), generateRandomNum(0, 9));
}

void testFirstNameSort(const vector<Human>& toSort){ //tests the FirstNameSort function for humans
    bool error = false;
    vector<Human> sorted = sortHumansByFirstName(toSort);
    for(int i=0; i < sorted.size()-1; ++i){
        if(sorted[i].getFirstName() > sorted[i+1].getFirstName()){
            cout << "Error: Human " << sorted[i].getFirstName() << " " << sorted[i].getLastName() 
            << "\nand human " << sorted[i+1].getFirstName() << sorted[i+1].getLastName() << " was not sorted correctly by first name." << endl;
            error = true;
        }
    }
    if(!error){
        cout << "First name sort test for humans passed!" << endl;
    }
}

void testLastNameSort(const vector<Human>& toSort){ //tests the LastNameSort function for humans
    bool error = false;
    vector<Human> sorted = sortHumansByLastName(toSort);
    for(int i=0; i < sorted.size()-1; ++i){
        if(sorted[i].getLastName() > sorted[i+1].getLastName()){
            cout << "Error: Human " << sorted[i].getFirstName() << " " << sorted[i].getLastName() 
            << "\nand human " << sorted[i+1].getFirstName() << sorted[i+1].getLastName() << " was not sorted correctly by last name." << endl;
            error = true;
        }
    }
    if(!error){
        cout << "Last name sort test for humans passed!" << endl;
    }
}

void testTrainingScoreSort(const vector<Human>& toSort){ //tests the TrainingScoreSort function for humans
    bool error = false;
    vector<Human> sorted = sortHumansByTrainingScore(toSort);
    for(int i=0; i < sorted.size()-1; ++i){
        if(sorted[i].getTrainingScore() < sorted[i+1].getTrainingScore()){
            cout << "Error: Human " << sorted[i].getFirstName() << " " << sorted[i].getLastName() 
            << "with training score " << sorted[i].getTrainingScore() 
            << "\nand  human " << sorted[i+1].getFirstName() << " " << sorted[i+1].getLastName() 
            << "with training score " << sorted[i+1].getTrainingScore() 
            << " was not sorted correctly by training score." << endl;
            error = true;
        }
    }
    if(!error){
        cout << "Training score sort test for humans passed!" << endl;
    }
}

void testMissionAptitudeSort(const vector<Human>& toSort){ //tests the MissionAptitudeSort function for humans
    bool error = false;
    vector<Human> sorted = sortHumansByMissionAptitude(toSort);
    for(int i=0; i < sorted.size()-1; ++i){
        if(sorted[i].getMissionAptitude() < sorted[i+1].getMissionAptitude()){
            cout << "Error: Human " << sorted[i].getFirstName() << " " << sorted[i].getLastName() 
            << "with a mission aptitude of " << sorted[i].getMissionAptitude() 
            << "\nand  human " << sorted[i+1].getFirstName() << " " << sorted[i+1].getLastName() 
            << "with a mission aptitude of " << sorted[i+1].getMissionAptitude() 
            << " was not sorted correctly by mission aptitude." << endl;
            error = true;
        }
    }
    if(!error){
        cout << "Mission aptitude sort test for humans passed!" << endl;
    }
}

void testOverallSort(const vector<Human>& toSort){ //tests the OverallSort function for humans
    bool error = false; 
    vector<Human> sorted = sortHumansOverall(toSort);
    for(int i=0; i < sorted.size()-1; ++i){
        if(sorted[i].getMissionAptitude() < sorted[i+1].getMissionAptitude()){
            cout << "Error: Human " << sorted[i].getFirstName() << " " << sorted[i].getLastName() 
            << "with a mission aptitude of " << sorted[i].getMissionAptitude() 
            << "\nand  human " << sorted[i+1].getFirstName() << " " << sorted[i+1].getLastName() 
            << "with a mission aptitude of " << sorted[i+1].getMissionAptitude() 
            << " was not sorted correctly in overall sort by mission aptitude." << endl;
            error = true;
        }
        else if(sorted[i].getMissionAptitude() == sorted[i+1].getMissionAptitude()){
            if(sorted[i].getTrainingScore() < sorted[i+1].getTrainingScore()){
                cout << "Error: Human " << sorted[i].getFirstName() << " " << sorted[i].getLastName() 
                << "with training score " << sorted[i].getTrainingScore() 
                << "\nand  human " << sorted[i+1].getFirstName() << " " << sorted[i+1].getLastName() 
                << "with training score " << sorted[i+1].getTrainingScore() 
                << " was not sorted correctly in overall sort by training score." << endl;
            error = true;
            }
            else if(sorted[i].getTrainingScore() == sorted[i+1].getTrainingScore()){
                if(sorted[i].getHomeSector() > sorted[i+1].getHomeSector()){
                    cout << "Error: Human " << sorted[i].getFirstName() << " " << sorted[i].getLastName() 
                    << "with home sector " << sorted[i].getHomeSector() 
                    << "\nand  human " << sorted[i+1].getFirstName() << " " << sorted[i+1].getLastName() 
                    << "with home sector " << sorted[i+1].getHomeSector() 
                    << " was not sorted correctly in overall sort by home sector." << endl;
            error = true;
                }
            }
        }

    }
    if(!error){
        cout << "Overall sort test for humans passed!" << endl;
    }
}

//alien tests

void testFirstNameSortAlien(const vector<Alien>& toSort){ //tests the FirstNameSort function for aliens
    bool error = false;
    vector<Alien> sorted = sortAliensByFirstName(toSort);
    for(int i=0; i < sorted.size()-1; ++i){
        if(sorted[i].getFirstName() > sorted[i+1].getFirstName()){
            cout << "Error: Alien " << sorted[i].getFirstName() << " " << sorted[i].getLastName() 
            << "\nand alien " << sorted[i+1].getFirstName() << sorted[i+1].getLastName() << " was not sorted correctly by first name." << endl;
            error = true;
        }
    }
    if(!error){
        cout << "Name sort test for aliens passed!" << endl;
    }
}

void testLastNameSortAlien(const vector<Alien>& toSort){ //tests the LastNameSort function for aliens
    bool error = false;
    vector<Alien> sorted = sortAliensByLastName(toSort);
    for(int i=0; i < sorted.size()-1; ++i){
        if(sorted[i].getLastName() > sorted[i+1].getLastName()){
            cout << "Error: Alien " << sorted[i].getFirstName() << " " << sorted[i].getLastName() 
            << "\nand alien " << sorted[i+1].getFirstName() << sorted[i+1].getLastName() << " was not sorted correctly by last name." << endl;
            error = true;
        }
    }
    if(!error){
        cout << "Last name sort test for aliens passed!" << endl;
    }
}

void testTrainingScoreSortAlien(const vector<Alien>& toSort){ //tests the TrainingScoreSort function for aliens
    bool error = false;
    vector<Alien> sorted = sortAliensByTrainingScore(toSort);
    for(int i=0; i < sorted.size()-1; ++i){
        if(sorted[i].getTrainingScore() < sorted[i+1].getTrainingScore()){
            cout << "Error: Alien " << sorted[i].getFirstName() << " " << sorted[i].getLastName() 
            << "with training score " << sorted[i].getTrainingScore() 
            << "\nand  Alien " << sorted[i+1].getFirstName() << " " << sorted[i+1].getLastName() 
            << "with training score " << sorted[i+1].getTrainingScore() 
            << " was not sorted correctly by training score." << endl;
            error = true;
        }
    }
    if(!error){
        cout << "Training score sort test for aliens passed!" << endl;
    }
}

void testMissionAptitudeSortAlien(const vector<Alien>& toSort){ //tests the MissionAptitudeSort function for aliens
    bool error = false;
    vector<Alien> sorted = sortAliensByMissionAptitude(toSort);
    for(int i=0; i < sorted.size()-1; ++i){
        if(sorted[i].getMissionAptitude() < sorted[i+1].getMissionAptitude()){
            cout << "Error: Alien " << sorted[i].getFirstName() << " " << sorted[i].getLastName() 
            << "with a mission aptitude of " << sorted[i].getMissionAptitude() 
            << "\nand  alien " << sorted[i+1].getFirstName() << " " << sorted[i+1].getLastName() 
            << "with a mission aptitude of " << sorted[i+1].getMissionAptitude() 
            << " was not sorted correctly by mission aptitude." << endl;
            error = true;
        }
    }
    if(!error){
        cout << "Mission aptitude sort test for aliens passed!" << endl;
    }
}

void testOverallSortAlien(const vector<Alien>& toSort){ //tests the OverallSort function for aliens
    bool error = false;
    vector<Alien> sorted = sortAliensOverall(toSort);
    for(int i=0; i < sorted.size()-1; ++i){
        if(sorted[i].getMissionAptitude() < sorted[i+1].getMissionAptitude()){
            cout << "Error: Alein " << sorted[i].getFirstName() << " " << sorted[i].getLastName() 
            << "with a mission aptitude of " << sorted[i].getMissionAptitude() 
            << "\nand  alien " << sorted[i+1].getFirstName() << " " << sorted[i+1].getLastName() 
            << "with a mission aptitude of " << sorted[i+1].getMissionAptitude() 
            << " was not sorted correctly in overall sort by mission aptitude." << endl;
            error = true;
        }
        else if(sorted[i].getMissionAptitude() == sorted[i+1].getMissionAptitude()){
            if(sorted[i].getTrainingScore() < sorted[i+1].getTrainingScore()){
                cout << "Error: Alien " << sorted[i].getFirstName() << " " << sorted[i].getLastName() 
                << "with training score " << sorted[i].getTrainingScore() 
                << "\nand  alien " << sorted[i+1].getFirstName() << " " << sorted[i+1].getLastName() 
                << "with training score " << sorted[i+1].getTrainingScore() 
                << " was not sorted correctly in overall sort by training score." << endl;
            error = true;
            }
            else if(sorted[i].getTrainingScore() == sorted[i+1].getTrainingScore()){
                if(sorted[i].getHomeworld() > sorted[i+1].getHomeworld()){
                    cout << "Error: Alien " << sorted[i].getFirstName() << " " << sorted[i].getLastName() 
                    << "with homeworld " << sorted[i].getHomeworld() 
                    << "\nand  alien " << sorted[i+1].getFirstName() << " " << sorted[i+1].getLastName() 
                    << "with homeworld " << sorted[i+1].getHomeworld() 
                    << " was not sorted correctly in overall sort by homeworld." << endl;
            error = true;
                }
            }
        }

    }
    if(!error){
        cout << "Overall sort test for aliens passed!" << endl;
    }
}

void testInvalidInputs(){ //tests the program's response to invalid inputs
    char choice;
    while(true){
        cout << "Would you like to test filtering invalid inputs? (Y/N):\n";
        cin >> choice;
        if(choice == 'Y' || choice == 'y'){
            cout << "Would you like to test for humans or aliens? (H/A):\n";
            char type;
            cin >> type;
            while(type != 'H' && type != 'h' && type != 'A' && type != 'a'){
                cout << "Invalid choice. Please enter H or A.\n";
                cin >> type;
            }
            if(type == 'H' || type == 'h'){
                vector<Human> invalidHumans;
                for (int i = 0; i < 100; ++i) { //generates potentially invalid  humans for testing
                    invalidHumans.push_back(createRandomInvalidHuman());
                }
                cout << "generated 100 humans with potentially invalid inputs.\n";
            }
            else if(type == 'A' || type == 'a'){
                vector<Alien> invalidAliens;
                for (int i = 0; i < 100; ++i) { //generates potentially invalid  aliens for testing
                    invalidAliens.push_back(createRandomInvalidAlien());
                }
                cout << "generated 100 aliens with potentially invalid inputs.\n";
            }
            else{
                cout << "Invalid choice. Please enter H or A.\n";
                continue;
            }
            vector<Human> invalidHumans;
            for (int i = 0; i < 100; ++i) { //generates potentially invalid  humans for testing
                invalidHumans.push_back(createRandomInvalidHuman());
            }
            cout << "generated 100 humans with potentially invalid inputs.\n";
            break;
        }
        else if(choice =='N' || choice == 'n'){
            cout << "Skipping invalid input tests.\n";
            break;
        }
        else if(choice !='N' && choice != 'n'){
            cout << "Invalid choice. Please enter Y or N.\n";
        }
    }
}