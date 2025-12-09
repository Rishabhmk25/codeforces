#include<iostream>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int k, a, b, x, y;
        cin >> k >> a >> b >> x >> y;
        int s = 0;
        if(k >= a && k >= b)
        {
            if(x < y)
            {    
                s += (k - a)/x + 1;
                k = a + (k - a)%x - x;
            }
            else
            {
                s += (k - b)/y + 1;
                k = b + (k - b)%y - y;
            }
        }
        if(k >= a)
        {
            s += (k - a)/x + 1;
            k = a + (k - a)%x - x;
        }
        if(k >= b)
        {
            s += (k - b)/y + 1;
            k = b + (k - b)%y - y;
        }
        cout<< s << endl;
    }
    return 0;
}
