#include <iostream>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while(t--)
    {
        long long int a, b, k;
        cin >> a >> b >> k;
        long long int temp, a1 = a, b1 = b;
        while(a1 != 0)
        {
            temp = a1;
            a1 = b1%a1;
            b1 = temp;
        }
        if(k >= a/b1 && k >= b/b1)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 2 << endl;
        }
    }
    return 0;
}

