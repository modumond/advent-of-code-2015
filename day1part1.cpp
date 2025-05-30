#include <iostream>
#include <fstream>
#include <string>
using namespace std;
 
int main() {
  int floor = 0;

  // Open the input text file
  ifstream file ("input1.txt");

  // Check if the file is successfully opened
  if (!file.is_open()) {
    cerr << "Error opening the file!";
    return 1;
  }

  // Read (the line of) the file, store it in string input
  string input;
  getline(file, input);

  for(char move : input) {
    if (move == '(') floor++;   // Go up one floor
    else if (move == ')') floor--;   // Go down one floor
  }

  // Result (floor)
  cout << floor << endl;

  // Close the file
  file.close();
  return 0;
}