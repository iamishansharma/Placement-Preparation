#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

void solve()
{
	int y,w;
	cin>>y>>w;

	if(y>w)
	{
		if(y == 6)
			cout<<"0/1"<<endl;
		else
		{
			int count = 0;

			for(int i=y; i<=6; i++)
				count++;

			if(count != 0)
			{
				if(6 % count == 0)
				{
					cout<<"1/"<<6/count<<endl;
				}
				else
				{
					if(count == 4)
						cout<<"2/3"<<endl;
					else
						cout<<count<<"/6"<<endl;
				}
			}
			else
			{
				cout<<"0/1"<<endl;
			}
		}
	}
	else
	{
		if(w == 6)
			cout<<"0/1"<<endl;
		else
		{
			int count = 0;

			for(int i=w; i<=6; i++)
				count++;

			if(count != 0)
			{
				if(6 % count == 0)
				{
					cout<<"1/"<<6/count<<endl;
				}
				else
				{
					if(count == 4)
						cout<<"2/3"<<endl;
					else
						cout<<count<<"/6"<<endl;
				}
			}
			else
			{
				cout<<"0/1"<<endl;
			}
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
}