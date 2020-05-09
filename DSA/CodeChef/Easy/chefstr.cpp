#include <bits/stdc++.h>
using namespace std;
string leftshift(string V)
{
	char first = V[0];

	for(int i=1; i<=V.length()-1; i++)
	{
		V[i-1] = V[i];
	}

	V[V.length()-1]=first;

	return V;
}
string rightshift(string V)
{
	char last = V[V.length()-1];

	for(int i=V.length()-2; i>=0; i--)
	{
		V[i+1] = V[i];
	}

	V[0] = last;

	return V;
}
int main()
{
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		string s;

		cin>>s;

		string left = leftshift(s);

		string right = rightshift(s);

		if(left == right)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}