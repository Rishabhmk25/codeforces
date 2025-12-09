#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<cmath>
using namespace std;
 
int main()
{
    int t, n, s;
    cin>>t;
    for(int i = 0; i < t; i++)
    {    
        cin>>n>>s;
        size_t l = n;
        vector<int> v(l);
        copy_n(istream_iterator<int>(cin), l, v.begin());
        sort(v.begin(), v.end());
        int a = abs(s-v[0]);
        int b = abs(s-v[n-1]);
        int x = max(a, b);
        int y = min(a, b);
        if(s > v[n-1] || s < v[0])
        {
            cout<<x<<endl;
        }
        else
        {
            cout<<2*y+x<<endl;
        }
    }
    return 0;
}
