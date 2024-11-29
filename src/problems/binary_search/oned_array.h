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
void take_input(std::vector<int> &vec, int &num);
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
void take_input(std::vector<int> &vec, int &num);
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
  void take_input(std::vector<int> &vec, int &num);
  SearchInsertPosition() { take_input(arr, num); }
};
