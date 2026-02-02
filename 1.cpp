#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  // Optimize I/O operations for speed
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  long long m; // Fix: m should be long long to prevent overflow in calculations
  if (!(cin >> n >> m))
    return 0;

  vector<string> v(n);
  vector<unordered_map<char, int>> freqs(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    unordered_map<char, int> freq;
    for (char c : v[i]) {
      freq[c]++;
    }
    freqs[i] = freq;
  }

  for (int i = 0; i < n; i++) {
    long long l = m; // Fix: l should be long long
    unordered_map<char, int> freq = freqs[i];
    bool possible = true;

    for (pair<const char, int> &a : freq) {
      long long d = a.second; // Fix: use long long for counts
      long long s = 0;        // Fix: use long long for sum

      for (int j = 0; j < n; j++) {
        if (j != i) {
          // Note: accessing freqs[j][a.first] creates an entry if it doesn't
          // exist, which is slow and modifies the map. Better to check if it
          // exists first.
          if (freqs[j].count(a.first)) {
            s += freqs[j][a.first];
          }
        }
      }

      // Logic Fix:
      // We need: k * s + d <= s * m
      // k * s <= s * m - d
      // k <= (s * m - d) / s

      if (s == 0) {
        // If s is 0, we have no copies of this char from other streets.
        // But we need 'd' copies for the current street (since d > 0).
        // Impossible.
        possible = false;
        break;
      }

      long long numerator = s * m - d;
      if (numerator < 0) {
        possible = false;
        break;
      }

      // Simplified formula replacing the if/else block
      l = min(l, numerator / s);
    }

    if (possible) {
      cout << l << " ";
    } else {
      cout << -1 << " ";
    }
  }
  cout << endl;
  return 0;
}
