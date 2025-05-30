#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <regex>
using namespace std;

int main() {
  set<pair<int, int>> lit_lights;
  
  // Open the input text file
  ifstream file ("input6.txt");

  // Check if the file is successfully opened
  if (!file.is_open()) {
    cerr << "Error opening the file!";
    return 1;
  }

  // Read each line of the file, store it in string input
  string input;
  while (getline(file, input)) {
   
    // Find coordinates
    string str = input;
    regex pattern ("\\d+");
    smatch match_result;
    vector<string> matches;
    while (regex_search(str, match_result, pattern)) {
      matches.push_back(match_result[0]);
      str = match_result.suffix().str();
    }

    int x_min = stoi(matches[0]);
    int y_min = stoi(matches[1]);
    int x_max = stoi(matches[2]);
    int y_max = stoi(matches[3]);

    // Figure out the instruction and apply it
    for (int x = x_min; x <= x_max; x++) {
      for (int y = y_min; y <= y_max; y++) {
        if (input.find("turn on") != string::npos) lit_lights.insert({ x, y });
        else if (input.find("turn off") != string::npos) lit_lights.erase({ x, y });
        else if (input.find("toggle") != string::npos) {
          bool is_lit = lit_lights.find({ x, y }) != lit_lights.end();
          if (is_lit) lit_lights.erase({ x, y });
          else lit_lights.insert({ x, y });
        }
      }
    }
  }

  // Result (number of lit lights)
  std::cout << lit_lights.size() << endl;

  return 0;
}
