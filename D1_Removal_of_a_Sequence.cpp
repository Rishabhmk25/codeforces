#include <iostream>
#include <vector>

using namespace std;

void solve() {
  long long x, y, k;
  if (!(cin >> x >> y >> k))
    return;

  if (y == 1) {
    cout << -1 << endl;
    return;
  }

  long long len = 1e12; // Initial length as per problem statement
  // Actually, the problem says "sequence of all natural numbers from 1 to
  // 10^12". But wait, is it exactly 10^12? "Polycarp has a sequence of all
  // natural numbers from 1 to 10^12." Yes.

  // Simulate length reduction
  vector<long long> lens;
  lens.push_back(len);
  for (int i = 0; i < x; ++i) {
    long long removed = len / y;
    len -= removed;
    lens.push_back(len);
  }

  if (k > len) {
    cout << -1 << endl;
    return;
  }

  // Map k backwards
  long long curr = k;
  for (int i = 0; i < x; ++i) {
    // We are at step x-i (end of step).
    // We want to go to step x-i-1 (start of step).
    // The mapping from old_index to new_index was removing multiples of y.
    // We need inverse: new_index -> old_index.

    long long q = (curr - 1) / (y - 1);
    long long r = (curr - 1) % (y - 1);
    curr = q * y + (r + 1);
  }

  cout << curr << endl;
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
