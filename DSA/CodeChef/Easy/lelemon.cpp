#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;

	int ord[m];

    for(int i=0;i<m;i++)
        cin>>ord[i];

    vector<vector<int>> bottle(n,vector<int>(100,0));

    int ci,x;

    for(int i=0;i<n;i++)
    {
        cin>>ci;
        for(int j=0; j<ci; j++)
            cin>>bottle.at(i).at(j);
    }

    ll sum=0;
    for(int i=0;i<m;i++)
    {
        sum += *max_element(bottle.at(ord[i]).begin(), bottle.at(ord[i]).end());
        bottle.at(ord[i]).at(max_element(bottle.at(ord[i]).begin(), bottle.at(ord[i]).end())-bottle.at(ord[i]).begin()) = 0;
    }
    cout<<sum<<endl;
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