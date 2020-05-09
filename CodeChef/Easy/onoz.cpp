#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

bool checkDoubleDigit(int n)
{
	int q=n/10;
	int p=n%10;
	if(p==q || q==0)
		return true;
	else
		return false;
}

int getSingleDigit(int n)
{
	return n%10;
}

int getDoubleDigit(int n)
{
	int q=n%10;
	return (q*10)+q;
}

void solve()
{
	int h,m,count=0;
	cin>>h>>m;
	for(int i =0;i<h;i++)
	{
		if(checkDoubleDigit(i))
		{
			if(getSingleDigit(i)<m)
				count++;
			if(getDoubleDigit(i)<m)
				count++;
		}
	}
	count--;
	cout<<count<<endl;
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