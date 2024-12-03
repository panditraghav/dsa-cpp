#include "input.h"
#include "oned_array.h"
#include "output.h"
#include <cstddef>
#include <fstream>
#include <iostream>
#include <ostream>

SingleElementInSortedArray::SingleElementInSortedArray() {
  std::fstream f;
  f.open("input.txt", std::ios_base::in);
  if (!get_vector_from_fstream(f, m_arr)) {
    std::cerr << "Unable to read file!" << std::endl;
    std::exit(EXIT_FAILURE);
  }
  std::cout << "Input array is: ";
  print_vector(m_arr);
}

/*
 * Using linear search
 */
void SingleElementInSortedArray::brute() {
  std::cout << "===================================\n";
  std::cout << "SingleElementInSortedArray::brute()\n";

  for (size_t i = 0; i < m_arr.size() - 1; i += 2) {
    if (m_arr[i] != m_arr[i + 1]) {
      std::cout << "The single element is: " << m_arr[i] << std::endl;
      return;
    }
  }

  std::cout << "The single element is: " << m_arr.back() << std::endl;
}
