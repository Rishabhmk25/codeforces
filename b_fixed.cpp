#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve() {
  int n;
  if (!(cin >> n))
    return;
  string s = "";
  for (int i = 0; i < n; i++) {
    string t;
    cin >> t;
    if (i == 0) {
      s = t;
    } else {
      if (t + s < s + t) {
        s = t + s;
      } else {
        s = s + t;
      }
    }
  }
  cout << s << endl;
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
