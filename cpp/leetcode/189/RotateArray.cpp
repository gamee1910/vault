#include "iostream"
#include "vector"


using namespace std;


class Solution {
  public:
    static void reverse(vector<int> &nums, int start, int end) {
      while (start < end) {
        swap(nums[start], nums[end]);
        start++;
        end--;
      }
    }
    static void rotate(vector<int> &nums, int k) {
      int n = nums.size();
      k = k % n;

      if (k == 0) return;

      reverse(nums, 0, n - 1);

      reverse(nums, 0, k - 1);

      reverse(nums, k, n - 1);
    }
};

int main() {
  vector nums{1, 2, 3, 4, 5, 6, 7};
  const int k = 3;

  Solution::rotate(nums, k);

  cout << "Rotate Array: " << k << " times" << endl;
  for (const int x: nums) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
