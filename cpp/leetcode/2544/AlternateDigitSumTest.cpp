//
// Created by game on 14-04-2026.
//
#include <gtest/gtest.h>
#include <utility>
#include <vector>
#include "AlternateDigitSum.h"

TEST(AlternateDigitSumTest, BasicExample) {
  EXPECT_EQ(Solution::alternateDigitSum(521), 4);
}

TEST(AlternateDigitSumTest, BasicTest) {
  EXPECT_EQ(Solution::alternateDigitSum(0), 0);
}

TEST(AlternateDigitSumTest, AdditionalCases) {
  const std::vector<std::pair<int, int>> cases = {
      {7, 7},
      {10, 1},
      {12, -1},
      {111, 1},
      {1111, 0},
      {909, 18},
      {1234, -2},
      {12345, 3},
      {1005, -4},
      {2147483647, -12},
  };

  for (const auto &[input, expected] : cases) {
    EXPECT_EQ(Solution::alternateDigitSum(input), expected);
  }
}

