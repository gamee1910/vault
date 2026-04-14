//
// Created by game on 14-04-2026.
//
#include "AlternateDigitSum.h"

int Solution::alternateDigitSum(const int num) {
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
