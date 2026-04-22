#include <iostream>
#include <vector>
using namespace std;

vector<int> groupsCheck(vector<int> &groups, int k) {
  vector<int> results(groups.size());

  int slow = 0, fast = (int)groups.size() - 1;

  for (int i = 0; i < (int)groups.size(); i++) {
    if (groups[i] <= k) {
      results[slow++] = groups[i];
    }
  }

  for (int i = 0; i < (int)groups.size(); i++) {
    if (groups[i] > k) {
      results[slow++] = groups[i];
    }
  }
  return results;
}

int main() {
  vector<int> groups = {3, 2, 7, 5, 6};
  vector<int> results = groupsCheck(groups, 5);

  for (int i : results) {
    cout << i << " ";
  }
  return 0;
}
