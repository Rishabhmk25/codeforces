#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n, x;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
      cin >> v[i];
    }
    cin >> x;
    int ma = *max_element(v.begin(), v.end());
    int mi = *min_element(v.begin(), v.end());
    if(x <= ma && x >= mi)
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }
  return 0;
}
