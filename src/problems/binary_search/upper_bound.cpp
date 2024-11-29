#include "input.h"
#include "oned_array.h"
#include "output.h"
#include <fstream>
#include <iostream>
#include <vector>

void find_upper_bound_in_sorted_array::take_input(std::vector<int> &vec,
                                                  int &num) {
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

void find_upper_bound_in_sorted_array::optimal_binary_search() {
  std::cout << "find_upper_bound_in_sorted_array::optimal_binary_search()\n";
  std::vector<int> vec;
  int num;
  find_upper_bound_in_sorted_array::take_input(vec, num);

  size_t low = 0, high = vec.size() - 1, mid = 0, upper_bound = vec.size() - 1;

  while (low <= high) {
    mid = (low + high) / 2;

    if (vec[mid] > num) {
      upper_bound = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  std::cout << "Upper bound of number is: " << vec[upper_bound]
            << "\nAt index: " << upper_bound << "\n";
}
