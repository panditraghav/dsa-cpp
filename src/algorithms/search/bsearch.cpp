#include "bsearch.h"
#include <cstddef>

int bsearch(std::vector<int> &arr, int target) {
  size_t low = 0, high = arr.size() - 1;

  while (low <= high) {
    size_t mid = (low + high) / 2;

    if (arr[mid] == target)
      return mid;

    if (arr[mid] < target) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return -1;
}
