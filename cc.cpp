#include <cmath>
#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) { return (n > 0) && ((n & (n - 1)) == 0); }

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (k % 2 == 1) {
      for (int i = 0; i < k; i++) {
        cout << n << ' ';
      }
      cout << "\n";
    } else {
      for (int i = 0; i < k - 2; i++) {
        cout << n << ' ';
      }
      if (n % 2 == 1) {
        cout << 0 << ' ' << n << endl;
      } else if (isPowerOfTwo(n)) {
        cout << 0 << ' ' << n << endl;
      } else {
        int rem = 0;
        int c = n;
        int a = 0;
        while (rem == 0) {
          rem = c % 2;
          c /= 2;
          a++;
        }
        int d = pow(2, a - 1);
        int b = 0;
        while (a--) {
          b += pow(2, a - 1);
        }
        cout << n - 1 << ' ' << d + b << endl;
      }
    }
  }
  return 0;
}
