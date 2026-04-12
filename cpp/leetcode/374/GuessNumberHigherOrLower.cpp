#include <iostream>

class Solution {
  public:
    static int guessNumber(const int n, const int pick) {
      int start = 1, end = n;
      while (start <= end) {
        const int mid = start + (end - start) / 2;
        const int target = guess(mid, pick);

        if (target == 0) {
          return mid;
        }
        if (target == -1) {
          end = mid - 1;
        } else {
          start = mid + 1;
        }
      }
      return -1;
    }

    static int guess(const int num, const int pick) {
      if (num == pick) return 0;
      return (num > pick) ? -1 : 1;
    }
};

int main() {
  constexpr int n = 10;
  constexpr int pick = 6;

  if (const int result = Solution::guessNumber(n, pick); result != -1) {
    std::cout << "Found: " << result << std::endl;
  } else {
    std::cout << "Not found!" << std::endl;
  }

  return 0;
}
