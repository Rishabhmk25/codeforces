#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n, m;
	    cin >> n >> m;
	    vector<int> v(m);
	    bool a = true;
	    for(int i = 0; i < m; i++)
	    {
	        cin >> v[i];
	        if(v[i] <= v[i-1] && i > 0)
	        {
	            a = false;
	        }
	    }
	    if(a)
	    {
	        cout << n-v[m-1]+1 << endl;
	    }
	    else
	    {
	        cout << 1 << endl;
	    }
	}
    return 0;
}
