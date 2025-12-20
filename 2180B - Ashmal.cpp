#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> v(n);
    string s = "";
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      if (s + v[i] > v[i] + s) {
        s = v[i] + s;
      } else {
        s = s + v[i];
      }
    }
    cout << s << endl;
  }
  return 0;
}
