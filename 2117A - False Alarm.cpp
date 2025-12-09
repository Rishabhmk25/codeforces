#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i = 0; i < t; i++)
    {
        int n, x;
        cin>>n>>x;
        size_t l = n;
        vector<int> v(l);
        copy_n(istream_iterator<int>(cin), l, v.begin());
        int s = 0, j = 0;
        for(int c: v)
        {
            if(c == 1)
            {
                s++;
            }
            if(s > 0)
            {
                x--;
            }
            if(c == 1 && x < 0)
            {
                cout<<"No"<<endl;
                break;
            }
            j++;
        }
        if(j == n)
        {
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}
