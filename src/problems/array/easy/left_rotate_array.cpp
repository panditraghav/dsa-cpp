#include "array_easy.h"
#include "input.h"
#include "output.h"
#include <fstream>
#include <ios>
#include <iostream>

bool get_input(std::vector<int> &vec, int &k) {
  std::cout << "left_rotate_array::simple()\n";

  std::fstream f("input.txt", std::ios::in);
  if (!f.is_open()) {
    std::cout << "Unable to open file!\n";
    return false;
  }
  if (!get_vector_from_fstream(f, vec))
    return false;
  if (!get_int_from_fstream(f, k))
    return false;

  std::cout << "Input vector:- ";
  print_vector(vec);
  std::cout << "Number of places to rotate: " << k << "\n";
  return true;
}

void reverse_vec(std::vector<int> &vec, int start, int end) {
  while (start < end) {
    int temp = vec[start];
    vec[start] = vec[end];
    vec[end] = temp;
    start++;
    end--;
  }
}

void left_rotate_array::temp_array() {

  std::vector<int> vec;
  int k;
  if (!get_input(vec, k))
    return;

  std::vector<int> to_end;
  to_end.resize(k);
  size_t i = 0, j = 0;
  for (; i < k; i++) {
    to_end[i] = vec[i];
  }
  for (; i < vec.size(); i++) {
    vec[j] = vec[i];
    j++;
  }
  for (; j < vec.size(); j++) {
    vec[j] = to_end[j - k + 1];
  }

  std::cout << "Left rotated array is: ";
  print_vector(vec);
}

/*
 * Input:
 *  Arr: 1 2 3 4 5
 *  K: 3
 * Reversing first part of array till k - 1
 * Arr: 3 2 1 4 5
 *
 * Reversing second part of array from k till end
 * Arr: 3 2 1 5 4
 *
 * Reversing whole array
 * Arr: 4 5 1 2 3
 */
void left_rotate_array::reverse_array() {
  std::cout << "left_rotate_array::reverse_array()\n";

  std::vector<int> vec;
  int k;
  if (!get_input(vec, k))
    return;

  reverse_vec(vec, 0, k - 1);
  reverse_vec(vec, k, vec.size() - 1);
  reverse_vec(vec, 0, vec.size() - 1);

  std::cout << "Left rotated array is: ";
  print_vector(vec);
}
