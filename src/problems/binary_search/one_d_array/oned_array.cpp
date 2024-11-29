#include "bsearch.h"
#include "input.h"
#include "output.h"
#include <fstream>
#include <ios>
#include <iostream>

void binary_search_test() {
  std::fstream f("input.txt", std::ios::in);
  if (!f.is_open()) {
    std::cerr << "ERROR: Unable to open file\n";
  }
  std::vector<int> vec;
  if (!get_vector_from_fstream(f, vec)) {
    std::cerr << "ERROR: Unable to get vector from file\n";
  }
  int target = 3;
  std::cout << "Input array: ";
  print_vector(vec);
  std::cout << "Target: " << target << "\n";

  std::cout << "Binary_search_iterative: Target is located at index: "
            << bsearch(vec, target) << "\n";

  std::cout << "Binary_search_recursive: Target is located at index: "
            << bsearch_recursive(vec, target, 0, vec.size() - 1) << "\n";
}
