#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

void solve()
{
	int n=0; 
	cin>>n;

	vector<int> v(n);

	vector<int> answer;
	
	for(int i=0; i<v.size(); i++)
		cin>>v[i];

	int max = INT_MIN;
	
	for(int i=n-1; i>=0; i--)
	{
		if(v[i] > max)
		{
			max = v[i];
			answer.push_back(v[i]);
		}
	}

	for(int i=answer.size()-1; i>=0; i--)
	{
		cout<<answer[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	fastIO;

	/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif*/
	
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
	return 0;
}