#include <iostream>
#include <string>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int operations = 0;
    int d = s[n-1];
    for(int i = 0; i < n-1; i++){
      if(s[i] != d){
        operations++;
      }
    }
    cout << operations << endl;
  }
  return 0;
}
