#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
using namespace std;

int main() {
  int ribbon = 0;

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

    // Smallest perimeter
    int perimeters[] = { 2*l+2*w, 2*w+2*h, 2*h+2*l };
    int n = sizeof(perimeters) / sizeof(perimeters[0]);
    int smallest_perimeter = *min_element(perimeters, perimeters + n);

    // Bow
    int bow_length = l*w*h;

    // Total length for the gift
    int total_length = smallest_perimeter + bow_length;

    // Add total surface to total of ribbon to order
    ribbon += total_length;
  }

  // Result (meters of ribbon)
  cout << ribbon << endl;

  // Close the file
  file.close();
  return 0;
}