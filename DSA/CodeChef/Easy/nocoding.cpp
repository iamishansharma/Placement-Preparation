#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

void solve()
{
	string str;
	cin>>str;

	char a[26];

	for(int i=0;i<26;i++)
		a[i]='a'+i;

	int l=str.length()+1;
	int first=-1,second=-1;

	for(int i=0; i<str.length(); i++)
	{
		char s=str[i];

		for(int i=0;i<26;i++)
		{
			if(s == a[i] && first==-1)
			{
				first=i;
				break;
			}
			else if(s==a[i]&&second==-1)
			{
				second=i;
				if(first>second)
				{
					int add=26-first+second;
					l=l+add;
				}
				else if(first<second)
				{
					l=l+second-first;
				}
				first=second;
				second=-1;
			}
		}
	}
	if(l>(11*str.length()))
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
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