#include "input.h"
#include "oned_array.h"
#include "output.h"
#include <fstream>
#include <ios>
#include <iostream>

void take_input(std::vector<int> &vec, int &num) {
  std::fstream f("input.txt", std::ios_base::in);
  if (!f.is_open()) {
    std::cerr << "ERROR: Unable to open file\n";
    return;
  }
  if (!get_vector_from_fstream(f, vec)) {
    std::cerr << "ERROR: Unable to get vector from input file\n";
    return;
  }
  std::cout << "Input vector:- ";
  print_vector(vec);

  if (!get_int_from_fstream(f, num)) {
    std::cerr << "ERROR: Unable to get number from input file\n";
    return;
  }
  std::cout << "Input number:- " << num << "\n";
}

// Iterating through the array to and returning the first
// occurance of number >= given number
// Linear search
void find_lower_bound_in_sorted_array::brute_linear_search() {
  std::cout << "find_lower_bound_in_sorted_array::brute()\n";
  std::vector<int> vec;
  int num;
  take_input(vec, num);

  for (size_t i = 0; i < vec.size(); i++) {
    if (vec[i] >= num) {
      std::cout << "Lower bound of number is: " << vec[i] << "\nAt index: " << i
                << "\n";
      break;
    }
  }
}

void find_lower_bound_in_sorted_array::optimal_binary_search() {
  std::cout << "find_lower_bound_in_sorted_array::optimal_binary_search()\n";
  std::vector<int> vec;
  int num;
  take_input(vec, num);

  size_t low = 0, high = vec.size() - 1, mid = 0;
  size_t lower_bound = vec.size() - 1;
  while (low <= high) {
    mid = (low + high) / 2;

    if (vec[mid] >= num) {
      high = mid - 1;
      lower_bound = mid;
    } else {
      low = mid + 1;
    }
  }
  std::cout << "Lower bound of number is: " << vec[lower_bound]
            << "\nAt index: " << lower_bound << "\n";
}
