#include <cmath>
#include <iostream>

using namespace std;

void solve() {
  int n;
  if (!(cin >> n))
    return;
  cout << (1 << n) - 1 << " ";
  for (int k = n - 1; k >= 0; --k) {
    int fixed_suffix = (1 << k) - 1;
    int limit = 1 << (n - 1 - k);
    for (int j = 0; j < limit; ++j) {
      int num = (j << (k + 1)) | fixed_suffix;
      cout << num << " ";
    }
  }
  cout << endl;
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
