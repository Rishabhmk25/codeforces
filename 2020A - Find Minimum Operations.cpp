#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i = 0; i < t; i++)
    {
        int n, k;
        cin>>n>>k;
        if(k == 1 || n < k)
        {
            cout<<n<<endl;
        }
        else
        {
            int s = 0;
            while(n > 0)
            {
                s += n%k;
                n /= k;
            }
            cout<<s<<endl;
        }
    }
    return 0;
}
