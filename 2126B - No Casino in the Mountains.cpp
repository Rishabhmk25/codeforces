#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        int s = 0;
        int total = 0;
        bool condition = true;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(condition)
            {
                if(a[i] == 0)
                {
                    s++;
                    if(s == k)
                    {
                        total++;
                        s = 0;
                        condition = false;
                    }
                }
                else
                {
                    s = 0;
                }
            }
            else
            {
                condition = true;
            }
        }
        cout << total << endl;
    }
    return 0;
}
