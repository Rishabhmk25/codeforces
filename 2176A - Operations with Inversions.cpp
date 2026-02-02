#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, ans = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    int current_max = -1;
    for (int i = 0; i < n; i++) {
      if (v[i] < current_max) {
        ans++;
      } else {
        current_max = v[i];
      }
    }
    cout << ans << endl;
  }
  return 0;
}
