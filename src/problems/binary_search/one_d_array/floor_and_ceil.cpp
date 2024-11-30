#include "input.h"
#include "oned_array.h"
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <iostream>

FloorAndCeil::FloorAndCeil() {
  std::cout << "FloorAndCeil::brute_linear()\n";
  if (!get_vector_and_num(this->arr, this->num)) {
    std::cerr << "Unable to read from file\n";
    std::exit(EXIT_FAILURE);
  };
}

void FloorAndCeil::brute_linear() {
  int floor = INT_MIN, ceil = INT_MIN;
  for (size_t i = 0; i < arr.size(); i++) {
    if (arr[i] <= num) {
      floor = arr[i];
    }
    if (ceil == INT_MIN && arr[i] >= num) {
      ceil = arr[i];
    }
  }

  std::cout << "Floor: " << floor << " Ceil: " << ceil << "\n";
}

/*
 * Arr: 3, 4, 4, 7, 8, 10
 * Num: 5
 */
void FloorAndCeil::optimal_binary() {
  int floor = INT_MIN, ceil = INT_MIN;
  size_t low = 0, high = arr.size() - 1, mid = 0;

  while (low <= high) {
    mid = (low + high) / 2;
    if (arr[mid] == num) {
      floor = arr[mid];
      ceil = arr[mid];
      break;
    }

    if (arr[mid] > num) {
      ceil = arr[mid];
      high = mid - 1;
    } else {
      floor = arr[mid];
      low = mid + 1;
    }
  }

  std::cout << "Floor: " << floor << " Ceil: " << ceil << "\n";
}
