#include <iostream>
#include <vector>
using namespace std;

bool isprime(long long a){
  if(a%2 == 0 && a > 2) return false;
  for(int i = 3; i*i <= a; i++){
    if(a%i == 0){
      return false;
    }
  }
  return true;
}

vector<long long> removed(int x, long long y){
  vector<long long> v;
  long long a = y;
  while(v.size() < x){
    if(isprime(a)) v.push_back(a);
    else{
      bool ok = true;
      for(auto c: v){
        if(a%c == 0){
          ok = false;
          break;
        }
      }
      if(ok){
        v.push_back(a);
      }
      a++;
    }
  }
  return v;
}

long long kth_term(vector<long long> v, long long k){
  long long a = v[v.size()-1];
  vector<long long> g;
  long long j = k;
  while(j > 0){
    a++;
    if(isprime(a)){
      j--;
      g.push_back(a);
    }
    else{
      for(long long c: g){
        if(a%c == 0){
          j--;
        }
      }
    }
  }
  return a;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int x;
    long long int y, k;
    cin >> x >> y >> k;
    if(y > 1){  
      vector<long long> v = removed(x, y);
      if(k >= y){
        long long a = kth_term(v, k - y + 1);
        if(a <= 1000000000000){
        cout << a << endl;
        }
        else{
          cout << -1 << endl;
        }
      }
      else{
        cout << k << endl;
      }
    }
    else{
      cout << -1 << endl;
    }
  }
  return 0;
}
