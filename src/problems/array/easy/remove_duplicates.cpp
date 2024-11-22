#include "array_easy.h"
#include "input.h"
#include "output.h"
#include <cstdio>
#include <fstream>
#include <ios>
#include <iostream>
#include <set>
#include <vector>

/**
 * Iterating over the input array and putting all element in a set
 * datastructure. Set doesn't have duplicate elements, then iterating again to
 * put unique elements back in the input array
 * Time complexity: O(n*log(n))+O(n)
 * Space Complexity: O(n)
 */
void remove_duplicates_from_sorted_array::brute_using_set() {
  std::cout << "\nremove_duplicates_from_sorted_array::using_set()\n";
  std::vector<int> vec;
  std::fstream f("input.txt", std::ios_base::in);

  if (!get_vector_from_fstream(f, vec)) {
    std::cout << "Unable to read file\n";
    return;
  }
  std::cout << "Input vector:- ";
  print_vector(vec);
  std::cout << "\n";

  std::set<int> unique;

  for (auto v : vec) {
    unique.insert(v);
  }
  size_t i = 0;
  for (auto v : unique) {
    vec[i] = v;
    i++;
  }
  std::cout << "Number of unique elements: " << i << std::endl;
  for (; i < vec.size(); i++) {
    vec[i] = 0;
  }

  std::cout << "Unique element vector:- ";
  print_vector(vec);
}

void remove_duplicates_from_sorted_array::optimal_two_pointers() {
  std::cout << "\nremove_duplicates_from_sorted_array::using_set()\n";
  std::vector<int> vec;
  std::fstream f("input.txt", std::ios_base::in);

  if (!get_vector_from_fstream(f, vec)) {
    std::cout << "Unable to read file\n";
    return;
  }
  std::cout << "Input vector:- ";
  print_vector(vec);
  std::cout << "\n";

  if (vec.size() == 1) {
    std::cout << "Array size is 1\n";
    return;
  }

  size_t i = 1, j = 1;
  int last_unique = vec[0];

  for (; i < vec.size(); i++) {
    int ati = vec[i];

    // If the element at current index is not equal to `last_unique`,
    // this means that this element is a unique element,
    // so we put this element at index j and increment j.
    // Index j will always be at duplicate element or j == i
    if (ati != last_unique) {
      vec[j] = ati;
      last_unique = ati;
      j++;
    }
  }
  std::cout << "Number of unique elements: " << j << "\n";
  for (; j < vec.size(); j++) {
    vec[j] = 0;
  }
  std::cout << "Unique elements vector: ";
  print_vector(vec);
}
