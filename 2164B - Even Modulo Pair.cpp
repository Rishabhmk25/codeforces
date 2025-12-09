#include <iostream>
#include <vector>
using namespace std;

pair<int, int> check(vector<int> v)
{
  int n = v.size();
  for(int i = 0; i < n; i++)
  {
    int x = v[i];
    for(int j = i+1; j < n; j++)
    {
      int y = v[j];
      int d = v[j]%v[i];
      if(d%2 == 0)
      {
        return {x, y};
      }
    }
  }
  return {0, 0};
}

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
    auto d = check(v);
    int a = d.first;
    int b = d.second;
    if(a != 0)
    {
      cout << a << ' ' << b << endl;
    }
    else
    {
      cout << -1 << endl;
    }
  }
  return 0;
}
