#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, x, y;
        cin >> a >> x >> y;
        int b = (x + y)/2;
        if(abs(y - x) < abs(a - x) || abs(y - x) < abs(a - y))
        {
            cout << "Yes" << endl;
        }
        else if(abs(x - b) < abs(x - a) && abs(y - b) < abs(y - a) && b != a)
        {
            cout << "Yes" << endl;
        }
        else if(abs(x - b - 1) < abs(x - a) && abs(y - b - 1) < abs(y - a) && b != a)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
