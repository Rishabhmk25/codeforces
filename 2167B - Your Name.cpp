#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int q;
	cin >> q;
	while(q--)
	{
	    int n;
	    cin >> n;
	    vector<char> s(n);
	    vector<char> t(n);
	    bool f = true;
	    for(int i = 0; i < n; i++)
	    {
	        cin >> s[i];
	    }
	    for(int i = 0; i < n; i++)
	    {
	        cin >> t[i];
	    }
	    sort(s.begin(), s.end());
	    sort(t.begin(), t.end());
	    for(int i = 0; i < n; i++)
	    {
	        if(s[i] != t[i])
	        {
	            f = false;
	            break;
	        }
	    }
	    if(f)
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
