#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> ones;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      ones.push_back(i);
    }
  }

  // It is guaranteed that at least one character is equal to 1.
  if (ones.empty()) {
    cout << n << endl;
    return;
  }

  int max_zeros = 0;
  int k = ones.size();
  for (int i = 0; i < k; ++i) {
    int u = ones[i];
    int v = ones[(i + 1) % k];
    // Calculate cyclic distance between adjacent 1s
    int dist = (v - u + n) % n;
    if (dist == 0)
      dist = n; // Case where there is only one '1'

    // The number of zeros between them is distance - 1
    max_zeros = max(max_zeros, dist - 1);
  }

  cout << max_zeros << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}