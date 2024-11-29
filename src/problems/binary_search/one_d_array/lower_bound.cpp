#include "input.h"
#include "oned_array.h"
#include <iostream>

// Iterating through the array to and returning the first
// occurance of number >= given number
// Linear search
void find_lower_bound_in_sorted_array::brute_linear_search() {
  std::cout << "find_lower_bound_in_sorted_array::brute()\n";
  std::vector<int> vec;
  int num;
  get_vector_and_num(vec, num);

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
  get_vector_and_num(vec, num);

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
