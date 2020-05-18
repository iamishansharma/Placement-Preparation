#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

int minMoves(int n, vector<int> a, int k) 
{ 
    int ct1[k] = {0}, ct0[k] = {0}, moves = 0;

    for (int i = 0; i < n; i++) 
        if (a[i] == 1) 
            ct1[i % k]++; 
        else
            ct0[i % k]++; 
  
    // Choose the minimum elements to change 
    for (int i = 0; i < k; i++) 
        moves += min(ct1[i], ct0[i]); 
  
    // Return the minimum moves required 
    return moves; 
}

void solve()
{
	int n=0;
	int k=0;
	cin>>n>>k;

	string s;
	cin>>s;

	vector<int> lamps(n);

	for(int i=0; i<s.length(); i++)
	{
		if(s[i] == '0')
			lamps[i] = 0;
		else
			lamps[i] = 1;
	}

	cout<<minMoves(n,lamps,k)<<endl;
}

int main()
{
	fastIO;

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif
	
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
	return 0;
}