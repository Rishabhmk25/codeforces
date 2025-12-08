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
    int n;
    long long int a;
    cin >> n >> a;
    vector<long long int> v(n);
    for(int i = 0; i < n; i++)
    {
      cin >> v[i];
    }
    long long int ma = *max_element(v.begin(), v.end());
    long long int mi = *min_element(v.begin(), v.end());
    if(a < mi)
    {
      cout << mi << endl;
    }
    else if (a > ma) 
    {
      cout << ma <<endl;
    }
    else
    {
      int h = 0;
      int c = 0;
      sort(v.begin(), v.end());
      for(int i = 0; i < n; i++)
      {
        h++;
        if(a < v[i])
        {
          break;
        }
        else if (a == v[i]) 
        {
          c = count(v.begin()+i, v.end(), v[i]);
          break;
        }
      }
      if(h > n-h-c+1)
      {
        cout << a-1 << endl;
      }
      else
      {
        cout << a+1 << endl;
      }
    }
  }
  return 0;
}
