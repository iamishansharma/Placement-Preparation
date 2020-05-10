#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

void solve()
{
	int k=0,n=0;
	cin>>k>>n;
	map<int,int> m;
	m.clear();

	while(k>0)
	{
		m[k%10]++;
		k=k/10;
	}

	if(m.size() == 3)
		cout<<"27"<<endl;
	else if(m.size() == 2)
		cout<<"8"<<endl;
	else
		cout<<"1"<<endl;
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