#include <iostream>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    if(n%2 == 0)
    {
      int out = n/4;
      cout << out + 1 << endl;
    }
    else
    {
      cout << 0 << endl;
    }
  }
  return 0;
}
