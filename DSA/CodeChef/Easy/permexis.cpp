#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

void solve()
{
	int n=0;
	cin>>n;

	vector<int> v(n);
	
	for(int i=0; i<v.size(); i++)
		cin>>v[i];
	
	sort(v.begin(),v.end());

	int flag = 0;

	for(int i=0; i<n-1; i++)
	{
		if(abs(v[i]-v[i+1]) <= 1)
		{
			// do nothing
		}
		else
		{
			flag = 1;
			break;
		}
	}

	if(flag == 0)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}

int main()
{
	fastIO;
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
	return 0;
}