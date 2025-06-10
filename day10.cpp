#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string GetNewSequence(string sequence, int iterations) {
  // Temp variable
  string new_sequence;

  // Doing it X times
  for (int time = 0; time < iterations; time++) {
    // Variable to store the number we're working with and how many times it appears in a row
    string str;
    str = sequence[0];

    for (int i = 1; i < sequence.size(); i++) {
      if (sequence[i] == sequence[i - 1]) {
        // If the current number is the same as the previous number, add it to str
        str += sequence[i];
      } else {
        // If the current number is not the same as the previous number,
        // process str : add how many times the number appears then the number itself to new sequence
        new_sequence += to_string(str.size()) + str[0];
        // and update str to be the current number
        str = sequence[i];
      }
    }
    // Processing again in order to take into account the last i
    new_sequence += to_string(str.size()) + str[0];
    
    // Updating the sequence to the new sequence and resetting the new_sequence;
    sequence = new_sequence;
    new_sequence = "";
  }

  return sequence;
}

int main() {
  // Puzzle input
  string sequence = "1113122113";
  
  // Solving Part 1
  // Result = length of the final sequence after applying the look-and-say process 40 times
  int result_one = GetNewSequence(sequence, 40).size();
  cout << result_one << endl;

  // Solving Part 2
  // Result = length of the final sequence after applying the look-and-say process 50 times
  int result_two = GetNewSequence(sequence, 50).size();
  cout << result_two << endl;

  return 0;
}
