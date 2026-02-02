#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
 
int main()
{
    int t, n, j, k;
    cin>>t;
    for(int i = 0; i < t; i++)
    {    
        cin>>n>>j>>k;
        size_t l = n;
        vector<int> v(l);
        copy_n(istream_iterator<int>(cin), l, v.begin());
        int p = v[j-1];
        sort(v.begin(), v.end());
        if(k >= 2)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            if(p == v[l-1])
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}
