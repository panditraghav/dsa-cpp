#include "input.h"
#include "oned_array.h"
#include <cstddef>
#include <iostream>

LastOccuranceInSortedArray::LastOccuranceInSortedArray() {
  std::cout << "LastOccuranceInSortedArray::LastOccuranceInSortedArray\n";
  get_vector_and_num(this->arr, this->num);
}

void LastOccuranceInSortedArray::brute_linear() {
  int last_occurance = -1;
  for (size_t i = 0; i < arr.size(); i++) {
    if (arr[i] == num) {
      last_occurance = i;
    }
  }
  std::cout << "Last occurance is: " << last_occurance << std::endl;
}

void LastOccuranceInSortedArray::better_linear() {
  int last_occurance = -1;
  for (size_t i = 0; i < arr.size(); i++) {
    if (arr[i] == num) {
      last_occurance = i;
    }
    // Since array is sorted, if current number is greater then num
    // then all nums after this will not be num
    if (arr[i] > num) {
      break;
    }
  }
  std::cout << "Last occurance is: " << last_occurance << std::endl;
}
