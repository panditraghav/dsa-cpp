#include "input.h"
#include "output.h"
#include <fstream>
#include <ios>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  // Open the text file named "input.txt"
  fstream f("input.txt", std::ios_base::in);

  // Check if the file is successfully opened
  if (!f.is_open()) {
    cerr << "Error opening the file!";
    return 1;
  }
  std::vector<std::vector<int>> mat;
  get_matrix_from_fstream(f, mat);
  print_matrix(mat);

  // Close the file
  f.close();
  return 0;
}
