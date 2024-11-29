#include "input.h"
#include "oned_array.h"
#include "output.h"
#include <cstddef>
#include <fstream>
#include <iostream>

void SearchInsertPosition::take_input(std::vector<int> &vec, int &num) {
  std::fstream f("input.txt", std::ios_base::in);
  if (!f.is_open()) {
    std::cerr << "ERROR: Unable to open file\n";
    return;
  }
  if (!get_vector_from_fstream(f, vec)) {
    std::cerr << "ERROR: Unable to get vector from input file\n";
    return;
  }
  std::cout << "Input vector:- ";
  print_vector(vec);

  if (!get_int_from_fstream(f, num)) {
    std::cerr << "ERROR: Unable to get number from input file\n";
    return;
  }
  std::cout << "Input number:- " << num << "\n";
}

void SearchInsertPosition::optimal() {
  std::cout << "SearchInsertPosition::optimal()\n";
  std::size_t low = 0, high = arr.size(), mid = 0;

  while (low <= high) {
    mid = (low + high) / 2;
    if (arr[mid] == num) {
      std::cout << "Search number found at index: " << mid << "\n";
      return;
    }
    if (arr[mid] > num) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  std::cout << "Search number not found!\n";
  std::cout << "Number should be inserted at index: " << mid << "\n";
}
