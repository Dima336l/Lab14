#include "SelectionSort.h"

void selectionSort(std::vector<int>& vec) {
  std::size_t x;
  for (std::size_t i = 0; i < vec.size() - 1; i++) {
    x = i;
    for (std::size_t j = i + 1; j < vec.size(); j++) {
      if (vec[j] < vec[i]) {
	x = j;
      }
    }
    if (x != i) {
      std::swap(vec[i], vec[x]);
    }
  }
}
