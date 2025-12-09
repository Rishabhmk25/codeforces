#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, x, y;
        cin>>n;
        cin>>x>>y;
        int time = 0;
        if(x >= y)
        {
            time += n/y;
            if(n % y != 0)
            {
                time++;
            }
        }
        else
        {
            time += n/x;
            if(n % x != 0)
            {
                time++;
            }
        }
        cout<<time<<endl;
    }
}
