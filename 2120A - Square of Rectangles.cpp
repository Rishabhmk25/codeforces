#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i = 0; i < t; i++)
    {
        int l1, b1, l2, b2, l3, b3;
        cin>>l1>>b1>>l2>>b2>>l3>>b3;
        if(l1 == l2 && l2 == l3 && b1+b2+b3 == l1)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        else if(b1 == b2 && b2 == b3 && l1+l2+l3 == b1)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        else if(l1+l2 == l3 && b1 == b2 && b1+b3 == l3)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        else if(l2+l3 == l1 && b2 == b3 && b2+b1 == l1)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        else if(l1+l3 == l2 && b1 == b3 && b1+b2 == l2)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        else if(b2+b3 == b1 && l2 == l3 && l2+l1 == b1)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        else if(b1+b3 == b2 && l1 == l3 && l1+l2 == b2)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        else if(b1+b2 == b3 && l1 == l2 && l1+l3 == b3)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        cout<<"No"<<endl;
    }
    return 0;
}
