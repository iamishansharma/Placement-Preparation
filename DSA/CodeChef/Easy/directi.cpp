#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

void solve()
{
	ll n;
    cin >> n;
    string str[n+1];
    for(ll i=0;i<n+1;i++)
    {
        getline(cin,str[i]);
    }
    string temp;
    vector<string> n1,n2;
    for(ll i=0;i<n+1;i++)
    {
        temp = str[i].substr(0,8);
        if(temp == "Begin on")
        {
            n1.push_back(temp);
            n2.push_back(str[i].substr(8,str[i].size()));
        }
        if(temp == "Right on")
        {
            n1.push_back(temp);
            n2.push_back(str[i].substr(8,str[i].size()));
        }
        temp = str[i].substr(0,7);
        if(temp == "Left on")
        {
            n1.push_back(temp);
            n2.push_back(str[i].substr(7,str[i].size()));
        }
    }
    ll x = n1.size();
    for(ll i=x-1;i>=0;i--)
    {
        if(i == x-1)
        {
            cout << "Begin on";
        }
        else if(n1[i+1] == "Right on")
        {
            cout << "Left on";
        }
        else
        {
            cout << "Right on";
        }
        cout << n2[i] <<endl;
    }
}

int main()
{
	//fastIO;

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout); 
	#endif
	
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
	return 0;
}