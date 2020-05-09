#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int p=0,s=0;
	cin>>p>>s;

	float l = (p - sqrt(p * p - 24 * s))/12;
	float v = l * s/2 - l * l * p/4 + l * l * l;
	
	cout<<fixed<<setprecision(2)<<v<<endl;
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