#include <vector>
void binary_search_test();

/*
 * Given a sorted array of N integers and an integer x,
 * write a program to find the lower bound of x.
 * Example 1:
 * Input Format:
 * N = 4, arr[] = {1,2,2,3}, x = 2
 * Result:
 * 1
 * Explanation:
 * Index 1 is the smallest index such that arr[1] >= x.
 *
 * Link: https://takeuforward.org/arrays/implement-lower-bound-bs-2/
 */
namespace find_lower_bound_in_sorted_array {
void brute_linear_search();
void optimal_binary_search();
} // namespace find_lower_bound_in_sorted_array

/*
 * Example 1:
 * Input Format:
 *  N = 4, arr[] = {1,2,2,3}, x = 2
 * Result:
 *  3
 * Explanation:
 *  Index 3 is the smallest index such that arr[3] > x.
 */
namespace find_upper_bound_in_sorted_array {
void optimal_binary_search();
} // namespace find_upper_bound_in_sorted_array

/*
 * Problem Statement: You are given a sorted array arr of distinct values and a
 * target value x. You need to search for the index of the target value in the
 * array. If the value is present in the array, then return its index.
 * Otherwise, determine the index where it would be inserted in
 * the array while maintaining the sorted order.
 */
class SearchInsertPosition {
private:
  std::vector<int> arr;
  int num;

public:
  void optimal();
  SearchInsertPosition();
};

/*
 * Problem Statement: You're given an sorted array arr of n integers and an
 * integer x. Find the floor and ceiling of x in arr[0..n-1]. The floor of x is
 * the largest element in the array which is smaller than or equal to x. The
 * ceiling of x is the smallest element in the array greater than or equal to x.
 * Example 1:
 * Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 5
 * Result: 4 7
 * Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the
 * array is 7.
 */
class FloorAndCeil {
private:
  std::vector<int> arr;
  int num;

public:
  void brute_linear();
  void optimal_binary();
  FloorAndCeil();
};

class LastOccuranceInSortedArray {
private:
  std::vector<int> arr;
  int num;

public:
  void brute_linear();
  void better_linear();
  void optimal_binary();
  void optimal_binary_upperbound();
  LastOccuranceInSortedArray();
};

class FirstOccuranceInSortedArray {
private:
  std::vector<int> arr;
  int num;

public:
  void optimal_binary_search_lowerbound();
  FirstOccuranceInSortedArray();
};

/*
 * Input : arr = [4,5,6,7,0,1,2,3], k = 0
 * Result: 4
 */
class SearchElementInRotatedArray {
private:
  std::vector<int> m_arr;
  int m_num;

public:
  void find_rotation_point_and_bsearch();
  void optimal_bsearch();
  SearchElementInRotatedArray();
};
