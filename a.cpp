#include <iostream>
#include <numeric>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
    int l, a, b;
    cin >> l >> a >> b;
    int g = gcd(l, b);
    int diff = (l-1-a)%g;
    cout << l-1-diff << endl;
  }
	return 0;
}
