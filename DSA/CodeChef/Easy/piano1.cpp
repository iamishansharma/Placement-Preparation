#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

void solve()
{
	string S;
	cin>>S;

	int n=0;
	cin>>n;

	int ul; 		// no. of keys between initial key and last key of pattern
	int i;
	int dif_scales; // no. of different scales possible
	int keys;
	int rep; 		// no. of repetitions

	for(i = 0, ul = 0; S[i] != '\0'; i++)
	{
		if(S[i] == 'T')
			ul += 2;
		if(S[i] == 'S')
			ul++;
	}

	keys = 12*n;

	dif_scales = 0;

	i = 1;

	rep = ul;

	while(rep <= keys)
	{
		dif_scales += (keys - rep);
		rep += ul;
	}

	cout<<dif_scales<<endl;
}

int main()
{
	fastIO;

	/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif*/
	
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
	return 0;
}