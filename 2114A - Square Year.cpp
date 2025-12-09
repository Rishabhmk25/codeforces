#include <iostream>
#include <cmath>
using namespace std;
 
int main() {
	int t;
    cin >> t;
    while(t--)
    {
        int x;
        cin >> x;
        int s = sqrt(x);
        if(s*s == x)
        {
            cout << s << " " << 0 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
