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

long long nextprime(long long a){
  if(a%2 == 0) a++;
  else a += 2;
  while(!isprime(a)){
    a += 2;
  }
  return a;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int x;
    long long y, k;
    cin >> x >> y >> k;
    //if()
  }
}
