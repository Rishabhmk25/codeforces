#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int a, b;
    cin >> a >> b;
    int x = lcm(a, b);
    if(a == b){
      cout << 0 << endl;
    }
    else if(x == a || x == b){
      cout << 1 << endl;
    }
    else{
      cout << 2 << endl;
    }
  }
  return 0;
}
