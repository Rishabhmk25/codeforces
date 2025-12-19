#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

void solve() {
  int l, a, b;
  if (!(cin >> l >> a >> b))
    return;

  // The reachable sections are those congruent to a modulo gcd(l, b).
  // We want the largest x in [0, l-1] such that x % g == a % g.
  int g = std::gcd(l, b);
  int target = l - 1;
  // We want to subtract the smallest non-negative amount from target
  // to match the remainder of 'a'.
  // Difference in remainders: (target - a) % g
  // We subtract that difference from target.
  // Ensure the modulo result is positive.
  int diff = (target - a) % g;
  if (diff < 0)
    diff += g;

  int max_val = target - diff;
  cout << max_val << "\n";
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
