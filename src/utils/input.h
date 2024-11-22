#pragma once
#include <fstream>
#include <vector>

bool get_vector_from_fstream(std::fstream &f, std::vector<int> &vec);
bool get_matrix_from_fstream(std::fstream &f,
                             std::vector<std::vector<int>> &mat);
bool get_int_from_fstream(std::fstream &f, int &i);
