#pragma once

/**
  * Problem Statement: Given an integer array sorted in non-decreasing order,
  * remove the duplicates in place such that each unique element appears only
  * once. The relative order of the elements should be kept the same.

  * If there are k elements after removing the duplicates,
  * then the first k elements of the array should hold the final result.
  * It does not matter what you leave beyond the first k elements.
  *
  * Example 1:
  *
  * Input:
  *  arr[1,1,2,2,2,3,3]
  *
  * Output:
  *  arr[1,2,3,_,_,_,_]
*/
namespace remove_duplicates_from_sorted_array {
void optimal_two_pointers();
void brute_using_set();
} // namespace remove_duplicates_from_sorted_array
