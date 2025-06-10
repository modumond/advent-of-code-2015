#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <set>
using namespace std;

// Function to get the input
vector<string> GetDistances() {
  vector<string> distances = {};

  // Open the input text file
  ifstream file ("input9.txt");

  // Check if the file is successfully opened
  if (!file.is_open()) {
    cerr << "Error opening the file";
  } else {
    // Read each line of the file, store it in string input
    string line;
    while (getline(file, line)) {
      distances.push_back(line);
    }
    // Close the file
    file.close();
  }

  return distances;
}

// Function to extract every city in the input
vector<string> GetCities(vector<string> distances) {
  set<string> cities;
  regex pattern ("(\\w*)\\sto\\s(\\w*)");
  
  for (string distance : distances) {
    smatch matches;
    if (regex_search(distance, matches, pattern)) {
      cities.insert(matches[1]);
      cities.insert(matches[2]);
    }
  }

  vector<string> v(cities.begin(), cities.end());
  return v;
}

// PERMUTATIONS

// Function to swap elements in an array
void Swap(vector<string>& arr, int i, int j) {
  string temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

// Function to find the possible permutations. Initial value of idx is 0.
void Permute(vector<vector<string>>& res, vector<string> arr, int index) {
  
  // Base case: if index reaches the size of the array, add the permutation to the result
  if (index == arr.size()) {
    res.push_back(arr);
    return;
  }

  // Permutations made by swapping each element starting from index `idx`
  for (int i = index; i < arr.size(); i++) {
    // Swapping
    Swap(arr, index, i);

    // Recursive call to create permutations for the next element
    Permute(res, arr, index + 1);

    // Backtracking
    Swap(arr, index, i);
  }
}

// Function to get the permutations
vector<vector<string>> GetRoutes(vector<string>& arr) {
  // Declaring result variable
  vector<vector<string>> res;

  // Calling permutations with index starting at 0
  Permute(res, arr, 0);
  return res;
}



int main() {
  int shortest_distance = -1;
  int longest_distance = -1;
  vector<string> distances = GetDistances();
  vector<string> cities = GetCities(distances);
  vector<vector<string>> routes = GetRoutes(cities);

  // Calculating total distance
  for (auto route : routes) {
    int total_distance = 0;
    regex pattern ("\\d+");

    for (int i = 0; i < route.size()-1; i++) {
      smatch match;
      int distance_between_cities;

      for (string distance : distances) {
        if (distance.find(route[i]) != string::npos && distance.find(route[i+1]) != string::npos) {
          if (regex_search(distance, match, pattern)) {
            distance_between_cities = stoi(match[0]);
          }
          break;
        }
      }

      total_distance += distance_between_cities;
    }

    // Updating the shortest distance
    if (shortest_distance < 0 || total_distance < shortest_distance) {
      shortest_distance = total_distance;
    }

    // Updating the longest distance
    if (longest_distance < 0 || total_distance > longest_distance) {
      longest_distance = total_distance;
    }
  }
          
  // Part 1's result
  std::cout << "Shortest distance : " << shortest_distance << endl;

  // Part 2's result
  std::cout << "Longest distance : " << longest_distance << endl;
  
  return 0;
}
