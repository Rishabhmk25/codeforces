#include <iostream>
using namespace std;

void solve() {
  long long n;
  int k;
  if (!(cin >> n >> k))
    return;

  if (k % 2 == 1) {
    for (int i = 0; i < k; ++i) {
      cout << n << (i == k - 1 ? "" : " ");
    }
    cout << "\n";
  } else {
    for (int i = 0; i < k - 2; ++i) {
      cout << n << " ";
    }

    int msb = -1;
    for (int i = 62; i >= 0; --i) {
      if ((n >> i) & 1) {
        msb = i;
        break;
      }
    }

    int smsb = -1;
    if (msb != -1) {
      for (int i = msb - 1; i >= 0; --i) {
        if ((n >> i) & 1) {
          smsb = i;
          break;
        }
      }
    }

    if (smsb == -1) {
      cout << 0 << " " << n << "\n";
    } else {
      long long b = (1LL << (smsb + 1)) - 1;
      long long a = n ^ b;
      cout << a << " " << b << "\n";
    }
  }
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
