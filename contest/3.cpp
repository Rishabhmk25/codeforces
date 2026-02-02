#include <algorithm>
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
  sort(a.begin(), a.end());
  cout << max(a[0], a[1] - a[0]) << endl;
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
