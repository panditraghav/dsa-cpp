#include "output.h"
#include <cstddef>
#include <iostream>

void print_vector(std::vector<int> &vec) {
  for (size_t i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << " ";
  }
}

void print_matrix(std::vector<std::vector<int>> &mat) {
  for (size_t i = 0; i < mat.size(); i++) {
    for (size_t j = 0; j < mat[i].size(); j++) {
      std::cout << mat[i][j] << " ";
    }
    std::cout << "\n";
  }
}
