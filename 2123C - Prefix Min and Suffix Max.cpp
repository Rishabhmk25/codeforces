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
	    vector <int> v(n);
	    for(int i = 0; i < n; i++)
	    {
	        cin >> v[i];
	    }
	    int mi = 1000001;
	    vector <int> suffix_max(n);
	    suffix_max[n-1] = v[n-1];
	    for(int i = n-2; i >= 0; --i)
	    {
	        suffix_max[i] = max(suffix_max[i+1], v[i]);
	    }
	    for(int i = 0; i < n; i++)
	    {
	        mi = min(mi, v[i]);
	        if(v[i] == mi || v[i] == suffix_max[i])
	        {
	            cout << 1;
	        }
	        else
	        {
	            cout << 0;
	        }
	    }
	    cout << "\n";
	}
    return 0;
}
