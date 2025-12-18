#include <iostream>
#include <vector>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, m;
    cin >> n >> m;
    vector<int> alice(n);
    vector<int> bob(m);
    for(int i = 0; i < n; i++){
      cin >> alice[i];
    }
    for(int i = 0; i < m; i++){
      cin >> bob[i];
    }

  }
  return 0;
}
