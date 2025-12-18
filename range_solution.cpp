#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

long long solve() {
  int n;
  cin >> n;
  vector<long long> a(n);
  long long total_sum = 0;
  vector<long long> prefix(n + 1, 0);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    total_sum += a[i];
    prefix[i + 1] = prefix[i] + a[i];
  }

  // We want to maximize: (r - l + 1)*(l + r) - (prefix[r] - prefix[l-1]) +
  // total_sum Maximize: (r - l + 1)*(l + r) - prefix[r] + prefix[l-1] (r - l +
  // 1)(l + r) = r^2 - l^2 + r + l Expression: (r^2 + r - prefix[r]) - (l^2 - l
  // - prefix[l-1])

  // Let max_gain be the max diff.
  // If max_gain < 0, we do 0 ops (sum stays total_sum).
  // Actually the problem implies "at most once".
  // Usually operation is beneficial if gain > 0.

  long long max_val = total_sum;

  // To implement O(N):
  // Iterate r from 1 to n.
  // We need min (l^2 - l - prefix[l-1]) for 1 <= l <= r.

  long long min_L_term = 1e18; // Infinity

  for (int r = 1; r <= n; ++r) {
    long long l = r; // Consider l=r as a candidate for min_L update
    long long current_L_term = l * l - l - prefix[l - 1];
    if (current_L_term < min_L_term) {
      min_L_term = current_L_term;
    }

    long long current_R_term = (long long)r * r + r - prefix[r];

    long long current_op_sum = current_R_term - min_L_term + total_sum;
    if (current_op_sum > max_val) {
      max_val = current_op_sum;
    }
  }

  return max_val;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  if (cin >> t) {
    while (t--) {
      cout << solve() << endl;
    }
  }
  return 0;
}
