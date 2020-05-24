#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	string s;
	cin>>s;

	int count = 0;

	for(int i=1; i<=(s.length()-2)/2; i++)
	{
		string s1;
		string s2;
		string s3;
		string s4;

		int other = (s.length() - 2*i)/2;

		s1 = s.substr(0, i);
		s2 = s.substr(i, i);
		s3 = s.substr(2*i, other);
		s4 = s.substr((2*i)+other, other);

		//cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<endl;

		if(s1 == s2 && s3 == s4)
		{
			count++;
		}
	}

	cout<<count<<endl;
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