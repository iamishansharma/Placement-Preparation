#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cout << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	int n=0;
	cin>>n;

	string s;
	cin>>s;

	int sum1=0;
	int sum2=0;

	vector<int> pos;

	for (int i = 0; i < s.length(); ++i) 
		if (s[i] == '[') 
			pos.push_back(i);

	int count = 0;
	int p = 0;
	long sum = 0;
  
	for(int i = 0; i < s.length(); ++i) 
	{
		if (s[i] == '[') 
		{ 
			++count; 
			++p; 
		} 
		else
			--count; 
  
		if(count < 0) 
		{
			sum += pos[p] - i; 
			swap(s[i], s[pos[p]]); 
			++p;
			count = 1; 
		} 
	}

	cout<<sum<<endl;
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