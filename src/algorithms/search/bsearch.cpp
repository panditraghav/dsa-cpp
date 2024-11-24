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

int bsearch_recursive(std::vector<int> &arr, int target, size_t low,
                      size_t high) {
  if (low > high) {
    return -1;
  }

  size_t mid = (low + high) / 2;

  if (arr[mid] == target) {
    return mid;
  }

  if (arr[mid] < target) {
    return bsearch_recursive(arr, target, low, mid - 1);
  } else {
    return bsearch_recursive(arr, target, mid + 1, high);
  }
}
