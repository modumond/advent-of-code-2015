#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;

bool HasPairOfTwoLetters(string str) {
  unordered_map<string, int> pairs;
  
  for (int i = 0; i < str.size() - 1; i++) {
    string pair = str.substr(i, 2);

    // Check if we've seen these two letters before and it was not immediately before (overlap)
    if (pairs.count(pair) && pairs[pair] < i - 1) {
      return true;
    }

    // Store the first occurrence of the pair
    if (!pairs.count(pair)) {
      pairs[pair] = i;
    }
  }

  return false;
}

bool HasRepeatingLetter(string str) {
  for (int i = 0; i < str.size() - 2; i++) {
    string trio = str.substr(i, 3);
    if (trio[0] == trio[2]) return true;
  }

  return false;
}

int main() {
  int nice_strings = 0;
  
  // Open the input text file
  ifstream file ("input5.txt");

  // Check if the file is successfully opened
  if (!file.is_open()) {
    cerr << "Error opening the file!";
    return 1;
  }

  // Read each line of the file, store it in string input
  string input;
  while (getline(file, input)) {
    // Check that the string fulfills the two conditions to be deemed nice
    if (HasPairOfTwoLetters(input) && HasRepeatingLetter(input)) nice_strings++;
  }

  // Result (number of nice strings)
  cout << nice_strings << endl;

  // Close the file
  file.close();
  return 0;
}
