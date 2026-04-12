#include<iostream>
#include<vector>

int BinarySearch(std::vector<int> &vec, int n) {
  int start = 0;
  int end = vec.size() - 1;

  while (start <= end) {
    const int mid = start + (end - start) / 2;

    if (vec[mid] == n)
      return mid;
    if (vec[mid] < n)
      start = mid + 1;
    else
      end = mid - 1;
  }

  return -1;
}

int main() {
  int n, index;
  std::vector<int> vec = {3, 5, 7, 11, 12, 16, 17, 52, 64, 101};

  std::cout << "Array elements :";
  for (const int &i: vec) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  std::cout << "Element to search : ";
  std::cin >> n;

  if ((index = BinarySearch(vec, n)) != -1)
    std::cout << "Element found at index : " << index << std::endl;
  else
    std::cout << "Element not found. " << std::endl;
  return 0;
}
