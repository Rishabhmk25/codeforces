#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int x, m = 9;
	    cin >> x;
	    while(x != 0)
	    {
	        m = min(x%10, m);
	        x /= 10;
	    }
	    cout << m << endl;
	}
    return 0;
}
