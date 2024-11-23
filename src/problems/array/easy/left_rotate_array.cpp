#include "array_easy.h"
#include "input.h"
#include "output.h"
#include <fstream>
#include <ios>
#include <iostream>

void left_rotate_array::temp_array() {
  std::cout << "left_rotate_array::simple()\n";

  std::fstream f("input.txt", std::ios::in);
  if (!f.is_open()) {
    std::cout << "Unable to open file!\n";
    return;
  }
  std::vector<int> vec;
  int k;
  get_vector_from_fstream(f, vec);
  get_int_from_fstream(f, k);

  std::cout << "Input vector:- ";
  print_vector(vec);
  std::cout << "Number of places to rotate: " << k << "\n";

  std::vector<int> to_end;
  to_end.resize(k);
  size_t i = 0, j = 0;
  for (; i < k; i++) {
    to_end[i] = vec[i];
  }
  for (; i < vec.size(); i++) {
    vec[j] = vec[i];
    j++;
  }
  for (; j < vec.size(); j++) {
    vec[j] = to_end[j - k + 1];
  }

  std::cout << "Left rotated array is: ";
  print_vector(vec);
}
