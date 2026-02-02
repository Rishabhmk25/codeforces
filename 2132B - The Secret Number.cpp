#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        long long int n, x = 10;
        cin >> n;
        int s = 0;
        vector <long long> v;
        while(n/x != 0)
        {
            long long int a = x + 1;
            if(n%a == 0)
            {
                s++;
                v.push_back(n/a);
            }
            x *= 10;
        }
        cout << s << endl;
        sort(v.begin(), v.end());
        for(long long int c: v)
        {
            cout << c << " ";
        }
        if(s != 0){    
            cout << "\n";
        }
    }
    return 0;
}
