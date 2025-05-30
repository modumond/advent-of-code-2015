#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <utility>
using namespace std;

int main() {
  // Declare set for visited houses and initialize with starting position
  set<pair<int, int>> houses;
  houses.insert({0, 0});
  // Initialization of the coordinates of Santa and Robo_Santa
  int santa_x = 0, santa_y = 0;
  int robo_x = 0, robo_y = 0;

  // Open the text file
  ifstream file ("input3.txt");

  // Check if the file is successfully opened
  if (!file.is_open()) {
    cerr << "Error opening the file!";
    return 1;
  }

  // Read (the line of) the file, store it in string input
  string input;
  getline(file, input);
  
  for (int i = 0; i < input.size(); i++) {
    // Determine who's moving depending on whether the iterator is even (Santa) or odd (Robo)
    int& x = (i % 2 == 0) ? santa_x : robo_x;
    int& y = (i % 2 == 0) ? santa_y : robo_y;

    // Update coordinates based on move
    if (input[i] == '^') ++y;
    else if (input[i] == 'v') --y;
    else if (input[i] == '>') ++x;
    else if (input[i] == '<') --x;

    // Add new coordinates to set
    houses.insert({x, y});
  }

  // Result (houses visited)
  std::cout << houses.size() << endl;

  // Close the file
  file.close();
  return 0;
}
