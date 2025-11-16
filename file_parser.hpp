#ifndef FILE_PARSER_HPP
#define FILE_PARSER_HPP

#include <vector>
#include <string>
#include "human.hpp"
#include "alien.hpp"

std::vector<Human> parseHumanFile(const std::string& filename);
std::vector<Alien> parseAlienFile(const std::string& filename);

#endif