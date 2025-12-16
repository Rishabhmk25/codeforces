#include <iostream>
#include <string>
using namespace std;

int max_time(string s) {
  int n = s.size();
  int ans = 0;
  int start = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '>') {
      start = i + 1;
    } else {
      ans = max(ans, i - start + 1);
    }
  }
  start = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '<') {
      start = i + 1;
    } else {
      ans = max(ans, i - start + 1);
    }
  }
  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int a1 = s.find("**");
    int a2 = s.find("><");
    int a3 = s.find(">*<");
    int a4 = s.find("*<");
    int a5 = s.find(">*");
    if (a1 != string::npos || a2 != string::npos || a3 != string::npos ||
        a4 != string::npos || a5 != string::npos) {
      cout << -1 << endl;
    } else {
      cout << max_time(s) << endl;
    }
  }
  return 0;
}
