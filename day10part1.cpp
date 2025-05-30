#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  string input = "1113122113";
  string new_input;

  // Doing it 40 times
  for (int time = 0; time < 40; time++) {
    // Variable to store the number we're working with and how many times it appears in a row
    string str;
    str = input[0];

    for (int i = 1; i < input.size(); i++) {
      if (input[i] == input[i - 1]) {
        // If the current number is the same as the previous number, add it to str
        str += input[i];
      } else {
        // If the current number is not the same as the previous number,
        // process str : add how many times the number appears then the number itself to new input
        new_input += to_string(str.size()) + str[0];
        // and update str to be the current number
        str = input[i];
      }
    }
    // Processing again in order to take into account the last i
    new_input += to_string(str.size()) + str[0];
    
    // Updating the input to the new input and resetting the new_input;
    input = new_input;
    new_input = "";
  }

  // Result = length of the final inputà
  cout << input.size() << endl;

  return 0;
}
