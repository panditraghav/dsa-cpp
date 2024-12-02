#pragma once
#include <vector>

namespace my_algos {
bool bsearch(std::vector<int> &arr, int start, int end, int key, size_t &ans);
int bsearch_recursive(std::vector<int> &arr, int target, int low, int high);
} // namespace my_algos
