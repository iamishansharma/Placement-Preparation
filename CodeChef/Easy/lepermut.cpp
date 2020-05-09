#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> v(n);
	
	for(int i=0; i<v.size(); i++)
		cin>>v[i];

	int localinv = 0;
	int inv = 0;

	for(int i=0; i<v.size()-1; i++)
	{
		if(v[i]>v[i+1])
			localinv++;

		for(int j=i+1; j<v.size(); j++)
			if(v[i]>v[j])
				inv++;
	}

	if(localinv == inv)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}

int main()
{
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
	return 0;
}