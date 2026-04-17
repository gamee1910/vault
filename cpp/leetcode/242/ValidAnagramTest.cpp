//
// Created by game on 14-04-2026.
//
#include "ValidAnagram.h"
#include <gtest/gtest.h>

TEST(AnagramTest, NegativeCases) {
  EXPECT_FALSE(Solution::isAnagram("rat", "car"));
  EXPECT_FALSE(Solution::isAnagram("hello", "world"));
}

TEST(AnagramTest, DifferentLength) {
  EXPECT_FALSE(Solution::isAnagram("a", "ab"));
  EXPECT_FALSE(Solution::isAnagram("anagram", "nagaramz"));
}

TEST(AnagramTest, SameCharsDifferentCount) {
  EXPECT_FALSE(Solution::isAnagram("aabb", "abbb"));
  EXPECT_FALSE(Solution::isAnagram("aa", "a"));
}
