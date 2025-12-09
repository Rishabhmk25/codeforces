#include<iostream>
using namespace std;
 
void f(int a, int b)
{
    if(a >= b)
    {
        cout<<a<<endl;
    }
    else
    {
        int x = b - a;
        if (x >= a)
        {
            cout<<"0"<<endl;
        }
        else
        {
            cout<<a-x<<endl;
        }
    }
}
 
int main()
{
    int t, a, b;
    cin>>t;
    for(int i = 0; i < t; i++)
    {
        cin>>a>>b;
        f(a, b);
    }
}
