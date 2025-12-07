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
	    unordered_map<int, int> freq;
	    for(int &i: v)
	    {
	        freq[i]++;
	    }
	    cout << (freq[-1]%2)*2 + freq[0] << endl; 
	}
    return 0;
}
