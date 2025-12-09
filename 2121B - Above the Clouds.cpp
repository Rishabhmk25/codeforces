#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
 
int main()
{
    int t,n;
    cin>>t;
    for(int i = 0; i < t; i++)
    {    
        cin>>n;
        string s;
        cin>>s;
        if(n == 3)
        {
            if(s[0] == s[1] || s[1] == s[2])
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
        }
        else
        {    
            int i = 0;
            for(char c : s)
            {
                int freq = count(s.begin(), s.end(), c);
                if(freq == 2)
                {
                    if(s[0] != c || s[n-1] != c)
                    {
                        cout<<"Yes"<<endl;
                        break;
                    }
                }
                else if(freq > 2)
                {
                    cout<<"Yes"<<endl;
                    break;
                }
                i++;
                if(i == n)
                {
                    cout<<"No"<<endl;
                }
            }
        }
    }
    return 0;
}
