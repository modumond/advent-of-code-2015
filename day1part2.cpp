#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  int floor = 0;

  // Open the text file
  ifstream file ("input1.txt");

  // Check if the file is successfully opened
  if (!file.is_open()) {
    cerr << "Error opening the file!";
    return 1;
  }

  // Read (the line of) the file, store it in string input
  string input;
  getline(file, input);

  for (int i = 0; i < input.length(); i++) {
    if (input[i] == '(') floor++;
    else if (input[i] == ')') floor--;

    if (floor == -1) {
      int position = i + 1;
      // Result (position)
      cout << position << endl;
      break;
    }
  }

  // Close the file
  file.close();
  return 0;
}