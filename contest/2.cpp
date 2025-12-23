#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  if (!(cin >> n))
    return;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  if (n == 0) {
    cout << 0 << endl;
    return;
  }
  long long total_diff = 0;
  for (int i = 0; i < n - 1; ++i) {
    total_diff += abs(a[i] - a[i + 1]);
  }
  long long max_reduction = 0;
  if (n > 1) {
    max_reduction = max(max_reduction, (long long)abs(a[0] - a[1]));
  }
  if (n > 1) {
    max_reduction = max(max_reduction, (long long)abs(a[n - 2] - a[n - 1]));
  }
  for (int i = 1; i < n - 1; ++i) {
    long long current_reduction = (long long)abs(a[i - 1] - a[i]) +
                                  abs(a[i] - a[i + 1]) -
                                  abs(a[i - 1] - a[i + 1]);
    max_reduction = max(max_reduction, current_reduction);
  }

  cout << total_diff - max_reduction << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  if (cin >> t) {
    while (t--) {
      solve();
    }
  }
  return 0;
}
