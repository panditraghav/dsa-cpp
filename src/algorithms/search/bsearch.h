#include <cstddef>
#include <vector>
int bsearch(std::vector<int> &arr, int target);

int bsearch_recursive(std::vector<int> &arr, int target, size_t low,
                      size_t high);
