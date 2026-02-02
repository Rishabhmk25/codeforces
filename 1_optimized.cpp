#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  long long m;
  if (!(cin >> n >> m))
    return 0;

  vector<string> v(n);
  vector<vector<int>> counts(n, vector<int>(26, 0));
  vector<long long> total_counts(26, 0);

  for (int i = 0; i < n; i++) {
    cin >> v[i];
    for (char c : v[i]) {
      counts[i][c - 'A']++;
      total_counts[c - 'A']++;
    }
  }

  for (int i = 0; i < n; i++) {
    long long max_k = 2e18; // Initialize with a large value
    bool possible = true;

    for (int c = 0; c < 26; c++) {
      long long current_street_count = counts[i][c];
      long long other_streets_count =
          (total_counts[c] - current_street_count) * m;

      // We need: k * (total_counts[c] - current_street_count) + 1 *
      // current_street_count <= total_available Wait, the problem says: from
      // letters of m copies of s1...sn (excluding sl), compose k copies of
      // s1...sn (excluding sl) AND at least one copy of sl. Total available
      // letters of char 'c': (total_counts[c] - counts[i][c]) * m Required for
      // k copies of others: k * (total_counts[c] - counts[i][c]) Required for 1
      // copy of sl: counts[i][c] So: k * (total_counts[c] - counts[i][c]) +
      // counts[i][c] <= (total_counts[c] - counts[i][c]) * m

      long long others_single_count = total_counts[c] - current_street_count;

      if (others_single_count == 0) {
        if (current_street_count > 0) {
          // If this char only appears in current street, we can't make even 1
          // copy of it if we need it? Actually, we have 0 copies of this char
          // available because we lost the order for street i. And we need
          // 'counts[i][c]' of it. Available: 0. Needed: counts[i][c] > 0.
          // Impossible.
          possible = false;
          break;
        }
        // If others_single_count == 0 and current_street_count == 0, this char
        // is not used at all. No constraint.
        continue;
      }

      // k * others + current <= others * m
      // k * others <= others * m - current
      // k <= m - current / others

      long long numerator = others_single_count * m - current_street_count;
      if (numerator < 0) {
        possible = false;
        break;
      }

      max_k = min(max_k, numerator / others_single_count);
    }

    if (possible) {
      cout << max_k << " ";
    } else {
      cout << -1 << " ";
    }
  }
  cout << endl;

  return 0;
}
