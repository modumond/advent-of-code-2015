#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

int main() {
  int wrapping_paper = 0;

  // Open the text file
  ifstream file ("input2.txt");

  // Check if the file is successfully opened
  if (!file.is_open()) {
    cerr << "Error opening the file!";
    return 1;
  }

  // Read each line of the file, store it in string s
  string s;
  while (getline(file, s)) {
    regex rgx ("\\d+");
    smatch m;
    vector<string> dimensions;
  
    while (regex_search (s, m, rgx)) {
      for (auto x : m) {
        dimensions.push_back(x);
      }
      s = m.suffix().str();
    }

    int l = stoi(dimensions[0]);
    int w = stoi(dimensions[1]);
    int h = stoi(dimensions[2]);

    // Surface of the gift
    int box_surface = 2*l*w + 2*w*h + 2*h*l;

    // Smallest surface (slack)
    int surfaces[] = { l*w, w*h, h*l };
    int n = sizeof(surfaces) / sizeof(surfaces[0]);
    int smallest_surface = *min_element(surfaces, surfaces + n);

    // Total surface
    int total_surface = box_surface + smallest_surface;

    // Add total surface to total of wrapping paper to order
    wrapping_paper += total_surface;
  }

  // Result (square meters of wrapping paper)
  cout << wrapping_paper << endl;

  // Close the file
  file.close();
  return 0;
}