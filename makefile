CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic
TARGET = recruitment_system
SOURCES = main.cpp crewmember.cpp human.cpp alien.cpp telepathiclinktest.cpp crew_sort.cpp file_parser.cpp tests.cpp
HEADERS = crewmember.hpp human.hpp alien.hpp telepathiclinktest.hpp crew_sort.hpp file_parser.hpp tests.hpp
OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: clean