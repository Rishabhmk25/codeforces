#include<iostream>
#include<iterator>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        vector<vector<int>> dimensions;
        while(m--)
        {
            int l, b, h;
            size_t s = 3;
            vector<int> dim(s);
            copy_n(istream_iterator<int>(cin), s, dim.begin());
            dimensions.push_back(dim);
        }
        vector<int> cubes;
        int a = 1, b = 2;
        cubes.push_back(a);
        cubes.push_back(b);
        for(int i = 2; i < n; i++)
        {
            int side = a + b;
            if(i % 2 != 0)
            {
                b = side;
            }
            else
            {
                a = side;
            }
            cubes.push_back(side);
        }
        for(vector<int> &dim : dimensions)
        {
            int l = dim[0], b = dim[1], h = dim[2];
            if(l >= cubes[n-1] && b >= cubes[n-1] && h >= cubes[n-1])
            {
                if(l >= cubes[n-1] + cubes[n-2] || b >= cubes[n-1] + cubes[n-2] || h >= cubes[n-1] + cubes[n-2])
                {
                    cout << "1";
                    continue;
                }
            }
            cout << "0";
        }
        cout << endl;
    }
    return 0;
}
