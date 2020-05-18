#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

void solve()
{
	string s1;
	string s2;

	cin>>s1>>s2;

	for(int i=0; i<s1.length(); i++)
		s1[i] = tolower(s1[i]);

	for(int i=0; i<s2.length(); i++)
		s2[i] = tolower(s2[i]);

	if(s1<s2)
		cout<<"-1"<<endl;
	else if(s2<s1)
		cout<<"1"<<endl;
	else
		cout<<"0"<<endl;
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