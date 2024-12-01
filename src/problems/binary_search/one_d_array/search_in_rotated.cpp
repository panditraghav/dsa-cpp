#include "bsearch.h"
#include "input.h"
#include "oned_array.h"
#include <cstddef>
#include <cstdlib>
#include <iostream>

SearchElementInRotatedArray::SearchElementInRotatedArray() {
  std::cout << "=====================================\n";
  std::cout << "-----SearchElementInRotatedArray-----\n";
  if (!get_vector_and_num(m_arr, m_num)) {
    std::cerr << "Unable to get vector and number!\n";
    exit(EXIT_FAILURE);
  }
}
void SearchElementInRotatedArray::find_rotation_point_and_bsearch() {
  std::cout << "=========================================\n";
  std::cout << "-----find_rotation_point_and_bsearch-----\n";

  size_t first_section = 0;

  /*
   * Array is increasing order, which means arr[i+1] > arr[i].
   * This condition will not be true for the point at which array
   * is rotated.
   */
  for (size_t i = 0; i < m_arr.size() - 1; i++) {
    if (m_arr[i] == m_num) {
      std::cout << "Number found at index: " << i << std::endl;
      return;
    }
    if (m_arr[i + 1] < m_arr[i]) {
      first_section = i;
      std::cout << "Found first section till index: " << first_section
                << std::endl;
      break;
    }
  }
  if (m_arr.back() == m_num) {
    std::cout << "Number found at index: " << m_arr.size() - 1 << std::endl;
    return;
  }
  /*
   * Once we have first_section index, then we can do binary search
   * at both sections of array
   */
  size_t bsearch_ans;

  if (my_algos::bsearch(m_arr, 0, first_section, m_num, bsearch_ans)) {
    std::cout << "Number found in first section at index: " << bsearch_ans
              << std::endl;
  } else if (first_section != m_arr.size() - 1 &&
             my_algos::bsearch(m_arr, first_section + 1, m_arr.size() - 1,
                               m_num, bsearch_ans)) {
    std::cout << "Number found in second section at index: " << bsearch_ans
              << std::endl;
  } else {
    std::cout << "Unable to find the number!" << std::endl;
  }
}

void SearchElementInRotatedArray::optimal_bsearch() {
  std::cout << "=========================\n";
  std::cout << "-----optimal_bsearch-----\n";

  int low = 0, high = m_arr.size() - 1, mid = 0;

  while (low <= high) {
    mid = (low + high) / 2;

    if (m_arr[mid] == m_num) {
      std::cout << "Number found at index: " << mid << std::endl;
      return;
    }

    // This means left side is sorted
    if (m_arr[low] <= m_arr[mid]) {
      // Our number is in this side!
      if (m_num >= m_arr[low] && m_num < m_arr[mid]) {
        high = mid - 1;
      } else {
        // Our number is on other side, which may or maynot be sorted
        low = mid + 1;
      }
    } else { // Right side is sorted
      if (m_num > m_arr[mid] && m_num <= m_arr[high]) {
        low = mid + 1;
      } else {
        // Our number is on other side, which may or maynot be sorted
        high = mid - 1;
      }
    }
  }

  std::cout << "Unable to find the number!" << std::endl;
}
