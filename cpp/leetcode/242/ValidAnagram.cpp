#include "ValidAnagram.h"

bool Solution::isAnagram(string s, string t) {
  if (s.size() != t.size()) {
    return false;
  }

  int arr[26] = {0};

  for (int i = 0; i < t.size(); i++) {
    arr[s[i] - 'a'] += 1;
    arr[t[i] - 'a'] -= 1;
  }

  for (const int &num : arr) {
    if (num != 0) {
      return false;
    }
  }
  return true;
}
