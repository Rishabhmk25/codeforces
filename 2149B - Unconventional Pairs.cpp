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
	    sort(v.begin(), v.end());
	    int m = 0;
	    for(int i = 1; i < n; i+=2)
	    {
	        m = max(m, abs(v[i] - v[i-1]));
	    }
	    cout << m << endl;
	}
    return 0;
}
