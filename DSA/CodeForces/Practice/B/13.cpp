#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

void solve()
{
	map<char,int> mp;

	mp.insert(pair<char, int>('A',0));
	mp.insert(pair<char, int>('B',0));
	mp.insert(pair<char, int>('C',0));

	string s;
	cin>>s;

	if(s[1]=='>')
		mp[s[0]]++;
	else 
		mp[s[2]]++;

	cin>>s;

	if(s[1]=='>')
		mp[s[0]]++;
	else
		mp[s[2]]++;

	cin>>s;

	if(s[1]=='>')
		mp[s[0]]++;
	else 
		mp[s[2]]++;

    if(mp['A']==1 && mp['B']==1 &&mp['C']==1)
    	cout<<"Impossible";
	else
	{
	    if(mp['A']==0)
	    	cout<<"A";
	    else if(mp['B']==0)
	    	cout<<"B";
	    else if(mp['C']==0)
	    	cout<<"C";

	    if(mp['A']==1)
	    	cout<<"A";
	    else if(mp['B']==1)
	    	cout<<"B";
	    else if(mp['C']==1)
	    	cout<<"C";

	    if(mp['A']==2)
	    	cout<<"A";
	    else if(mp['B']==2)
	    	cout<<"B";
	    else if(mp['C']==2)
	    	cout<<"C";
	}
}

int main()
{
	fastIO;

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout); 
	#endif
	
	solve();
}