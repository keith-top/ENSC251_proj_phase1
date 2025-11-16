#ifndef TESTS_HPP
#define TESTS_HPP

#include <vector>
#include "human.hpp"
#include "alien.hpp"
using namespace std;

string generateRandomString(const int length);
int generateRandomNum(int min, int max);
int generateRandomFloat(float min, float max);

Human createRandomHuman();
Human createRandomInvalidHuman();
Alien createRandomAlien();
Alien createRandomInvalidAlien();

//human tests
void testFirstNameSort(const vector<Human>& toSort);
void testLastNameSort(const vector<Human>& toSort);
void testTrainingScoreSort(const vector<Human>& toSort);
void testMissionAptitudeSort(const vector<Human>& toSort);
void testOverallSort(const vector<Human>& toSort);
void testInvalidInputs();

//alien tests
void testFirstNameSortAlien(const vector<Alien>& toSort);
void testLastNameSortAlien(const vector<Alien>& toSort);
void testTrainingScoreSortAlien(const vector<Alien>& toSort);
void testMissionAptitudeSortAlien(const vector<Alien>& toSort);
void testOverallSortAlien(const vector<Alien>& toSort);
#endif