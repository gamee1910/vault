#include<iostream>
#include<vector>

int BinarySearch(std::vector<int> &nums, int target) {
  int start = 0, end = nums.size() - 1;

  while (start <= end) {
    const int mid = start + (end - start) / 2;

    if (nums[mid] == target)
      return mid;
    if (nums[mid] < target)
      start = mid + 1;
    else
      end = mid - 1;
  }

  return -1;
}

int main() {
  int target;
  std::vector nums = {3, 5, 7, 11, 12, 16, 17, 52, 64, 101};

  std::cout << "Array elements :";
  for (const int &i: nums) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  std::cout << "Element to search : ";
  std::cin >> target;

  if (int index; (index = BinarySearch(nums, target)) != -1)
    std::cout << "Element found at index : " << index << std::endl;
  else
    std::cout << "Element not found. " << std::endl;
  return 0;
}
