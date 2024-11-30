#include "input.h"
#include "oned_array.h"
#include <iostream>

FirstOccuranceInSortedArray::FirstOccuranceInSortedArray() {
  get_vector_and_num(this->arr, this->num);
}

void FirstOccuranceInSortedArray::optimal_binary_search_lowerbound() {
  std::cout
      << "FirstOccuranceInSortedArray::optimal_binary_search_lowerbound()\n";

  size_t low = 0, high = arr.size() - 1, mid = 0;
  size_t lower_bound = arr.size() - 1;

  while (low <= high) {
    mid = (low + high) / 2;

    if (arr[mid] >= num) {
      high = mid - 1;
      lower_bound = mid;
    } else {
      low = mid + 1;
    }
  }
  std::cout << "First occurance is at index: " << lower_bound << "\n";
}
