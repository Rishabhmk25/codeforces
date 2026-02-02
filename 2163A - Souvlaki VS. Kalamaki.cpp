#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    bool ok = true;
    for(int i = 1; i < n-1; i += 2)
    {
      if(v[i] != v[i+1]) ok = false;
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
