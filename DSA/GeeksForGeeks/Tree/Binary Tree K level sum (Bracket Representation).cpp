#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

int kLevelSum(string & s, int k)
{
    int n = s.size();
    
    unordered_map<int, int> levelToSum;
    
    string num = "";
    
    int level = -1;         // tracks current level
    
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '(')
        {    // level increase
            level += 1;
            
            if(num != "" && level > 0)
            {
                levelToSum[level - 1] += stoi(num);
                num = "";
            }
        }
        else if(isdigit(s[i]) == true)
        {
            num += s[i];
        }
        else
        {
            level -= 1;     // level decrese when find ')'
        }
    }
    return levelToSum[k];
}

void solve()
{
	int k=0;
	cin>>k;
	
	string s;
	cin>>s;
	
	int ans = kLevelSum(s, k);
	
    cout<<ans<<endl;
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