#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    long long n;
    int k;
    cin >> n >> k;

    if (k % 2 == 1) {
      // Odd k: output n repeated k times
      // XOR: n^n^...^n = n (odd times)
      // Sum: k * n (maximum possible)
      for (int i = 0; i < k; i++) {
        cout << n << (i < k - 1 ? " " : "\n");
      }
    } else {
      // Even k: output (k-2) copies of n, then two numbers a, b such that a^b =
      // n The (k-2) copies XOR to 0, so we need a^b = n To maximize a+b, note
      // that a+b = (a^b) + 2*(a&b) = n + 2*(a&b) We want to maximize a&b while
      // keeping a, b <= n

      // Strategy: Find highest set bit (MSB) and second highest set bit (SMSB)
      // in n If n is power of 2: no SMSB, best is (n, 0), sum = n Otherwise:
      // set b = (1 << (smsb+1)) - 1 (all bits from 0 to smsb)
      //            a = n ^ b
      //            Both a, b <= n, and a&b is maximized

      for (int i = 0; i < k - 2; i++) {
        cout << n << " ";
      }

      int msb = -1, smsb = -1;
      for (int i = 62; i >= 0; i--) {
        if ((n >> i) & 1) {
          if (msb == -1) {
            msb = i;
          } else {
            smsb = i;
            break;
          }
        }
      }

      if (smsb == -1) {
        // n is power of 2
        cout << 0 << " " << n << "\n";
      } else {
        long long b = (1LL << (smsb + 1)) - 1;
        long long a = n ^ b;
        cout << a << " " << b << "\n";
      }
    }
  }
  return 0;
}
