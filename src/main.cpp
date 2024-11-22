#include <bits/stdc++.h>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> split_string_to_vector(string str, char deliminator) {
  vector<int> vec;
  string cur = "";
  for (size_t i = 0; i < str.length(); i++) {
    if (str[i] == deliminator) {
      vec.push_back(stoi(cur));
      cur = "";
      continue;
    }
    cur += str[i];
  }
  vec.push_back(stoi(cur));
  return vec;
}

void print_vector(vector<int> vec) {
  for (size_t i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
  }
}

int main() {
  // Open the text file named "input.txt"
  ifstream f("../input.txt");

  // Check if the file is successfully opened
  if (!f.is_open()) {
    cerr << "Error opening the file!";
    return 1;
  }

  // String variable to store the read data
  string s;

  // Read each line of the file and print it to the
  // standard output stream till the whole file is
  // completely read
  while (getline(f, s)) {
    // cout << s << endl;
    print_vector(split_string_to_vector(s, ' '));
  }

  // Close the file
  f.close();
  return 0;
}
