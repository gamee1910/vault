//
// Created by game on 11-04-2026.
//
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution {
  public:
    static int maxOperations(vector<int> &nums, int k) {
      sort(nums.begin(), nums.end());
      int left = 0, right = static_cast<int>(nums.size()) - 1;
      int count = 0;
      while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == k) {
          count++;
          left++;
          right--;
        } else if (sum < k) {
          left++;
        } else {
          right--;
        }
      }
      return count;
    }
};

int main(int argc, char *argv[]) {
  vector<int> nums{4, 4, 1, 3, 1, 3, 2, 2, 5, 5, 1, 5, 2, 1, 2, 3, 5, 4};
  int k = 2;
  cout << Solution::maxOperations(nums, k) << endl;
  return 0;
}
