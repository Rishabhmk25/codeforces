#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

long long max_sum(vector<int> v) {
  int n = v.size();
  long long total_sum = 0;
  for (int x : v)
    total_sum += x;

  long long ans = total_sum;

  // FIX: Iterate through ALL possible ranges [i, j].
  // Do not return early.
  // We strictly perform the check for every pair to find the global maximum.
  for (int i = 0; i < n; i++) {
    long long current_range_sum = 0;
    for (int j = i; j < n; j++) {
      current_range_sum += v[j]; // Sum of elements v[i]...v[j]

      // Problem uses 1-based indexing for the replacement value: (l + r)
      // Our 0-based index i matches 1-based l = i + 1
      // Our 0-based index j matches 1-based r = j + 1
      // Replacement value = (i + 1) + (j + 1) = i + j + 2
      long long replacement_value = (long long)(i + j + 2);
      long long replacement_len = (j - i + 1);

      long long new_range_sum = replacement_value * replacement_len;

      // Total if we apply this operation
      long long candidate_ans = total_sum - current_range_sum + new_range_sum;

      if (candidate_ans > ans) {
        ans = candidate_ans;
      }
    }
  }
  return ans;
}

int main() {
  int t;
  if (cin >> t) {
    while (t--) {
      int n;
      cin >> n;
      vector<int> v(n);
      for (int i = 0; i < n; i++) {
        cin >> v[i];
      }
      cout << max_sum(v) << endl;
    }
  }
  return 0;
}
