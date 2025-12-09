#include<iostream>
using namespace std;
 
void f(int x)
{
    int k = 0;
    int j = 0;
    for(int i = 1; i < 101; i++)
    {
        if(i%2 == 0)
        {
            j = j - (2*i - 1);
        }
        else
        {
            j = j + (2*i - 1);
        }
        k++;
        if(j > x)
        {
            k = k + 1;
            break;
        }
        else if(j < -x)
        {
            k = k + 1;
            break;
        }
    }
    if(k % 2 == 0)
        {
            cout<<"Sakurako"<<endl;
        }
    else if (k % 2 == 1)
        {
            cout<<"Kosuke"<<endl;
        }
}
 
int main()
{
    int t, x;
    cin>>t;
    for(int i = 0; i < t; i++)
    {
        cin>>x;
        f(x);
    }
}
