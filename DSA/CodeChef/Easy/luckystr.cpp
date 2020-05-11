#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

void solve()
{
	int k=0, n=0;
	cin>>k>>n;

	string subs[k];

	for(int i=0; i<k; i++)
	{
		cin>>subs[i];
	}

	for(int i=0; i<n; i++)
	{
		string str;
		cin>>str;

		if(str.length()>=47)
			cout<<"Good"<<endl;
		else
		{
			int m=0;
			for(m=0; m<k; m++)
			{
				if(str.find(subs[m]) != -1)
				{
					cout<<"Good"<<endl;
					break;
				}
			}
			if(m==k)
				cout<<"Bad"<<endl;
		}
	}
}

int main()
{
	fastIO;

	/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif*/
	
	solve();
	return 0;
}