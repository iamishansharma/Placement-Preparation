#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin >> n;
		int max = -1;
		while (n--)
		{
			int s,v,p;
			cin >> s >> p >> v;
			if(p/(s+1)*v > max)
				max = p/(s+1)*v;
		}
		cout << max << '\n';
	}
	return 0;
}