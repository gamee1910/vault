//
// Created by game on 14-04-2026.
//
#include <string>
#include <iostream>
using namespace std;
class Solution {
  public:
    static int alternateDigitSum(const int num) {
      const string s = to_string(num);
      int sum = 0;

      for (int i = 0; i < s.size(); i++) {
        const int digit = s[i] - '0';
        if (i % 2 == 0) {
          sum += digit;
        } else
          sum -= digit;
      }
      return sum;
    }
};

int main() {
  cout << Solution::alternateDigitSum(521);
}
