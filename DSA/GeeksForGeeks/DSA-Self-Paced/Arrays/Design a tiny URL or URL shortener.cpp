#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

string encodeURL(ll n)
{
    string url = "";
    
    string lex = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    
    map<int,int> m;
    
    for(int i=0; i<lex.size(); i++)
        m[lex[i]] = i+1;
    
    while(n > 0)
    {
        int index = n % 62;
        n /= 62;
        url += lex[index];
    }
    
    reverse(url.begin(), url.end());
    
    return url;
}

ll decodeURL(string url)
{
    ll id = 1;
    
    string lex = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    map<int,int> m;
    
    for(int i=0; i<lex.size(); i++)
        m[lex[i]] = i+1;
        
    for(int i=0; i<url.size(); i++)
        id += (m[url[i]]-1)*pow(62,url.size()-1-i);
    
    return id-1;
}

void solve()
{
	ll id=0;
	cin>>id;
	
	string url = encodeURL(id);
	
	cout<<url<<endl;
	cout<<decodeURL(url)<<endl;
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