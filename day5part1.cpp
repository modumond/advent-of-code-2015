#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool HasThreeVowels(string str) {
  int vowels = 0;

  for (char c : str) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') vowels += 1;
    if (vowels >= 3) break;
  }

  return (vowels >= 3);
}

bool HasDoubleLetter(string str) {
  char letter = str[0];

  for (int i = 1; i < str.length(); i++) {
    if (str[i] == letter) return true;
    else letter = str[i];
  }

  return false;
}

bool HasNoDisallowedSubstrings(string str) {
  string disallowed_substrings[4] = { "ab", "cd", "pq", "xy" };

  for (string substr : disallowed_substrings) {
    if (str.find(substr) != string::npos) return false;
  }

  return true;
}

int main() {
  int nice_strings = 0;

  // Open the text file
  ifstream file ("input5.txt");

  // Check if the file is successfully opened
  if (!file.is_open()) {
    cerr << "Error opening the file!";
    return 1;
  }

  // Read each line of the file, store it in string input
  string input;
  while (getline(file, input)) {
    // Check that the string fulfills the three conditions to be deemed nice and added to the total of nice strings
    if (HasThreeVowels(input) && HasDoubleLetter(input) && HasNoDisallowedSubstrings(input)) nice_strings++;
  }

  // Result (number of nice strings)
  cout << nice_strings << endl;

  // Close the file
  file.close();
  return 0;
}
