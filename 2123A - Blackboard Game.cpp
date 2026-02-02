#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
 
int main()
{
    int t, n;
    cin>>t;
    for(int i = 0; i < t; i++)
    {    
        cin>>n;
        if(n%4 == 0)
        {
            cout<<"Bob"<<endl;
        }
        else
        {
            cout<<"Alice"<<endl;
        }
    }
    return 0;
}
