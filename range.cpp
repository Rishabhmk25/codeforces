#include <iostream>
#include <vector>
using namespace std;

int max_sum(vector<int> v){
  int maximum_sum = 0;
  for(int c: v){
    maximum_sum += c;
  }
  int n = v.size();
  for(int i = 0; i < n; i++){
    if(v[n-i-1] < 2*(n-i)){
      int sum = 0;
      int new_sum = 0;
      for(int j = i; j < n; j++){
        if((j - i + 1) * (2 * n - i - j) < new_sum + v[n-1-j]){
          return (j - i) * (2 * n + 1 - i - j) + maximum_sum - sum; 
        }
        else{
          sum += v[n-j-1];
          new_sum = (j - i + 1) * (2 * n - i - j);
        }
      }
      return new_sum + maximum_sum - sum;
    }     
  }
  return maximum_sum;
}

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
    cout << max_sum(v) << endl;
  }
  return 0;
}
