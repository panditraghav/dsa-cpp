#include "bsearch.h"

bool my_algos::bsearch(std::vector<int> &arr, int start, int end, int key,
                       size_t &ans) {
  while (start <= end) {
    size_t mid = (start + end) / 2;

    if (arr[mid] == key) {
      ans = mid;
      return true;
    }

    if (arr[mid] < key) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return false;
}

int my_algos::bsearch_recursive(std::vector<int> &arr, int target, int low,
                                int high) {
  if (low > high) {
    return -1;
  }

  int mid = (low + high) / 2;

  if (arr[mid] == target) {
    return mid;
  }

  if (arr[mid] < target) {
    return bsearch_recursive(arr, target, low, mid - 1);
  } else {
    return bsearch_recursive(arr, target, mid + 1, high);
  }
}
