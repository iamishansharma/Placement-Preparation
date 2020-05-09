#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

int main()
{
	fastIO;
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		int a, b, c, d;
		cin>>a>>b>>c>>d;
		cout << (float)a/(float)(a+b) << endl;
	}
	return 0;
}