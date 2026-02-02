#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i = 0; i < t; i++)
    {
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        if(a < b)
        {
            if(a < d)
            {
                cout<<"Flower"<<endl;
            }
            else
            {
                if(c < d)
                {
                    cout<<"Flower"<<endl;
                }
                else
                {
                    cout<<"Gellyfish"<<endl;
                }
            }
        }
        else
        {
            if(b <= c)
            {
                cout<<"Gellyfish"<<endl;
            }
            else
            {
                if(d <= c)
                {
                    cout<<"Gellyfish"<<endl;
                }
                else
                {
                    cout<<"Flower"<<endl;
                }
            }
        }
    }
    return 0;
}
