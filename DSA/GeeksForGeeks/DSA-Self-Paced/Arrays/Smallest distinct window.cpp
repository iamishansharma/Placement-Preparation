#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

int SmallestDistinctWindow(string s)
{
    int n = s.size();
    unordered_map<char,int>mp;
    unordered_set<char>st;
    
    for(int i=0; i<n; i++)
        st.insert(s[i]);
        
    int count = st.size();

    int l=0,r=0;
    
    int ans = n;
    
    mp[s[0]]++;
    
    while(l<=r)
    {
        if(mp.size()==count)
            ans = min(ans,r-l+1);
        
        if(r+1<n and mp.size()<count)
        {
            r++;
            mp[s[r]]++;
        }
        else
        {
            mp[s[l]]--;
            
            if(mp[s[l]]==0)
                mp.erase(s[l]);
                
            l++;
        }
    }
    return ans;
}

void solve()
{
	string s;
	cin>>s;
	
	cout<<SmallestDistinctWindow(s)<<endl;
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