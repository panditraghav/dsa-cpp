#include "input.h"
#include "oned_array.h"
#include "output.h"
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>

NumberOfRotation::NumberOfRotation() {
  std::fstream f;
  f.open("input.txt", std::ios_base::in);
  if (!get_vector_from_fstream(f, m_arr)) {
    std::cerr << "Unable to read file!" << std::endl;
    std::exit(EXIT_FAILURE);
  }
  print_vector(m_arr);
}

/*
 * Input: 4 5 6 7 0 1 2 3
 * To find the number of rotation, we find the index of minimum number.
 * That will be the number of rotation since array is sorted.
 * If 0 rotation minimum will be at index 0
 */
void NumberOfRotation::optimal_bsearch() {
  std::cout << "============================================\n";
  std::cout << "NumberOfRotation::optimal_bsearch()\n";

  int low = 0, high = m_arr.size() - 1, mid = 0;
  size_t min_index = 0;

  while (low <= high) {
    mid = (low + high) / 2;

    // If left half is sorted
    if (m_arr[low] <= m_arr[mid]) {
      if (m_arr[low] < m_arr[min_index]) {
        min_index = low;
      }

      // If both left and right half are sorted then,
      // this minimum will be the final min, no need to search
      // on other half
      if (m_arr[low] <= m_arr[high]) {
        break;
      }
      low = mid + 1;
    } else {
      if (m_arr[mid] < m_arr[min_index]) {
        min_index = mid;
      }
      high = mid;
    }
  }

  std::cout << "Number of rotations in given array is: " << min_index
            << std::endl;
}
