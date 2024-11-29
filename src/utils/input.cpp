#include "input.h"
#include "output.h"
#include <cstddef>
#include <iostream>
#include <string>

bool get_vector_from_string(std::string str, std::vector<int> &vec) {
  char deliminator = ' ';

  std::string cur = "";

  for (size_t i = 0; i < str.length(); i++) {
    if (str[i] == deliminator) {
      vec.push_back(stoi(cur));
      cur = "";
      continue;
    }
    cur += str[i];
  }
  vec.push_back(stoi(cur));
  return true;
}

bool get_vector_from_fstream(std::fstream &f, std::vector<int> &vec) {
  std::string str;

  if (!f.is_open()) {
    return false;
  }
  if (!getline(f, str)) {
    return false;
  }

  get_vector_from_string(str, vec);
  return true;
}

bool get_matrix_from_fstream(std::fstream &f,
                             std::vector<std::vector<int>> &mat) {

  if (!f.is_open()) {
    return false;
  }

  std::string line;

  while (getline(f, line)) {
    std::vector<int> row;
    get_vector_from_string(line, row);
    mat.push_back(row);
  }

  return true;
}

bool get_int_from_fstream(std::fstream &f, int &i) {

  std::string str;

  if (!f.is_open()) {
    return false;
  }
  if (!getline(f, str)) {
    return false;
  }

  i = std::stoi(str);
  return true;
}

bool get_vector_and_num(std::vector<int> &vec, int &num) {
  std::fstream f("input.txt", std::ios_base::in);
  if (!f.is_open()) {
    std::cerr << "ERROR: Unable to open file\n";
    return false;
  }
  if (!get_vector_from_fstream(f, vec)) {
    std::cerr << "ERROR: Unable to get vector from input file\n";
    return false;
  }
  std::cout << "Input vector:- ";
  print_vector(vec);

  if (!get_int_from_fstream(f, num)) {
    std::cerr << "ERROR: Unable to get number from input file\n";
    return false;
  }
  std::cout << "Input number:- " << num << "\n";
  return true;
}
