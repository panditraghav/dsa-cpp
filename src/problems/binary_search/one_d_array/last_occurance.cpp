#include "input.h"
#include "oned_array.h"
#include <cstddef>
#include <iostream>

LastOccuranceInSortedArray::LastOccuranceInSortedArray() {
  std::cout << "LastOccuranceInSortedArray::LastOccuranceInSortedArray\n";
  get_vector_and_num(this->arr, this->num);
}

void LastOccuranceInSortedArray::brute_linear() {
  std::cout << "brute_linear\n";
  int last_occurance = -1;
  for (size_t i = 0; i < arr.size(); i++) {
    if (arr[i] == num) {
      last_occurance = i;
    }
  }
  std::cout << "Last occurance is: " << last_occurance << std::endl;
}

void LastOccuranceInSortedArray::better_linear() {
  std::cout << "better_linear\n";
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
// Using binary search first finding the element.
// then iterating after it to see get the last element
void LastOccuranceInSortedArray::optimal_binary() {
  std::cout << "optimal_binary\n";
  size_t low = 0, mid = 0, high = arr.size() - 1;
  int num_index = -1;

  while (low <= high) {
    mid = (low + high) / 2;

    if (arr[mid] == num) {
      num_index = mid;
      break;
    }

    if (arr[mid] > num) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  if (num_index == -1) {
    std::cout << "Element not found!\n";
    return;
  }
  while (arr[num_index] == num) {
    num_index += 1;
  }
  std::cout << "Last occurance is: " << num_index - 1 << std::endl;
}

/*
 * Using binary search, to find the upper bound and then.
 * Upperbound - 1 will be the last occurance
 */
void LastOccuranceInSortedArray::optimal_binary_upperbound() {
  std::cout << "LastOccuranceInSortedArray::optimal_binary_upperbound()\n";
  size_t low = 0, high = arr.size() - 1, mid = 0;
  int ub = -1;
  int equal = -1;

  while (low <= high) {
    mid = (low + high) / 2;

    if (arr[mid] == num) {
      low = mid + 1;
      // If upper bound doesn't exist (num is the last element).
      // Then this will be the last element
      equal = mid;
    }

    if (arr[mid] > num) {
      ub = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  if (ub == -1) {
    if (equal == -1) {
      std::cout << "Element doesn't exist\n";
      return;
    } else {
      std::cout << "Last occurance is at index: " << equal;
      return;
    }
  }
  std::cout << "Last occurance is at index: " << ub - 1;
}
