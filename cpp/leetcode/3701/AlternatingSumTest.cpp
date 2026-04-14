//
// Created by game on 14-04-2026.
//
#include <gtest/gtest.h>
#include <vector>
#include "AlternatingSum.h"
using namespace std;


TEST(AlternatingSumTest, BasicExample) {
  EXPECT_EQ(Solution::alternatingSum({1, 3, 5, 7}), -4);
}

TEST(AlternatingSumTest, SingleElement) {
  EXPECT_EQ(Solution::alternatingSum({5}), 5);
}

TEST(AlternatingSumTest, TwoElements) {
  EXPECT_EQ(Solution::alternatingSum({10, 3}), 7);
}

TEST(AlternatingSumTest, EmptyVector) {
  EXPECT_EQ(Solution::alternatingSum({}), 0);
}

TEST(AlternatingSumTest, AllSameElements) {
  EXPECT_EQ(Solution::alternatingSum({2, 2, 2}), 2);
}
