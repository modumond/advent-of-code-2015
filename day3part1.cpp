#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <utility>
using namespace std;

int main() {
  // Declare set for visited houses and initialize with starting position
  // (using a set so that coordinates are not repeated)
  set<pair<int, int>> houses;
  houses.insert({0, 0});
  // Initialization of Santa's coordinates
  int x = 0, y = 0;

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

  for (char move : input) {
    // Update coordinates based on move
    if (move == '^') ++y;
    else if (move == 'v') --y;
    else if (move == '>') ++x;
    else if (move == '<') --x;

    // Add new coordinates to set
    houses.insert({x, y});
  }

  // Result (houses visited)
  std::cout << houses.size() << endl;

  // Close the file
  file.close();
  return 0;
}