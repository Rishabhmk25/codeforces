#include <iostream>
using namespace std;

int hao(int m){
  if(m > 2){
    int m1 = m/3;
    int m2 = m/3;
    int m3 = m - m1 - m2;
    return m1 + hao(m3);
  }
  else{
    return 0;
  }
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int m;
    cin >> m;
    cout << hao(m) << endl;
  }
  return 0;
}
