#include <iostream>
#include <vector>
using namespace std;

bool isprime(long long a){
  if(a == 2) return true;
  if(a%2 == 0) return false;
  for(long long i = 3; i*i < a; i++){
    if(a%i == 0) return false;
  }
  return true;
}



int main(){
  int t;
  cin >> t;
  while(t--){
    int x;
    long long y, k;
    cin >> x >> y >> k;
  }
}
