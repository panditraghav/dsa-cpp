#include "input.h"
#include "oned_array.h"
#include "output.h"
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>

FindMinimumInRotatedArray::FindMinimumInRotatedArray() {
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
 * If left half is sorted that means the that may not contain the minimum
 * Because the minimum will be on the unsorted side
 */
void FindMinimumInRotatedArray::optimal_bsearch() {
  std::cout << "============================================\n";
  std::cout << "FindMinimumInRotatedArray::optimal_bsearch()\n";

  int low = 0, high = m_arr.size() - 1, mid = 0, min = INT_MAX;

  while (low <= high) {
    mid = (low + high) / 2;

    // If left half is sorted
    if (m_arr[low] <= m_arr[mid]) {
      min = std::min(m_arr[low], min);

      // If both left and right half are sorted then,
      // this minimum will be the final min, no need to search
      // on other half
      if (m_arr[low] <= m_arr[high]) {
        break;
      }
      low = mid + 1;
    } else {
      min = std::min(m_arr[mid], min);
      high = mid;
    }
  }

  std::cout << "The minimum element in the array is: " << min << std::endl;
}
