#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    bool f = false;
	    vector<int> v(n);
	    for(int i = 0; i < n; i++)
	    {
	        cin >> v[i];
	    }
	    int m = v[0]%2;
	    for(int &c: v)
	    {
	        if(c%2 != m)
	        {
	            f = true;
	            break;
	        }
	    }
	    if(f)
	    {
	        sort(v.begin(), v.end());
	        for(int &c: v)
	        {
	            cout << c << " ";
	        }
	    }
	    else
	    {
	        for(int &c: v)
	        {
	            cout << c << " ";
	        }    
	    }
	    cout << "\n";
	}
	return 0;
}
