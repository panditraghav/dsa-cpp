#include "input.h"
#include <cstddef>
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
