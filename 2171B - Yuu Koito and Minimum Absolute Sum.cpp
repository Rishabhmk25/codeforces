#include <iostream>
#include <vector>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
      cin >> v[i];
    }
    if(v[0] != -1 && v[n-1] != -1){
      cout << abs(v[n-1] - v[0]) << endl;
    }
    else if(v[0] == -1){
      cout << 0 << endl;
      v[0] = v[n-1];
    }
    else if (v[n-1] == -1){
      cout << 0 << endl;
      v[n-1] = v[0];
    }
    for(int i = 0; i < n; i++){
      if(v[i] == -1){
        v[i] = 0;
      }
    }
    for(int c: v){
      cout << c << ' ';
    }
    cout << "\n";
  }
  return 0;
}
