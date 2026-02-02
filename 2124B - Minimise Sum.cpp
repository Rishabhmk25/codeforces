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
	    vector<int> v(n);
	    for(int i = 0; i < n; i++)
	    {
	        cin >> v[i];
	    }
	    cout << v[0] + min(v[0], v[1]) << endl;
	}
    return 0;
}
