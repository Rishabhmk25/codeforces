#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
 
int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int> v(n);
	    for(int i = 0; i < n; i++)
	    {
	        cin >> v[i];
	    }
	    unordered_map<int,int> freq;
	    for(int &c: v)
	    {
	        freq[c]++;
	    }
	    cout << freq.size()*2 - 1 << endl;
	}
    return 0;
}
