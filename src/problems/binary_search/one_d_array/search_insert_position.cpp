#include "input.h"
#include "oned_array.h"
#include <cstddef>
#include <iostream>

void SearchInsertPosition::optimal() {
  std::cout << "SearchInsertPosition::optimal()\n";
  std::size_t low = 0, high = arr.size(), mid = 0;

  while (low <= high) {
    mid = (low + high) / 2;
    if (arr[mid] == num) {
      std::cout << "Search number found at index: " << mid << "\n";
      return;
    }
    if (arr[mid] > num) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  std::cout << "Search number not found!\n";
  std::cout << "Number should be inserted at index: " << mid << "\n";
}

SearchInsertPosition::SearchInsertPosition() {
  get_vector_and_num(this->arr, this->num);
}
