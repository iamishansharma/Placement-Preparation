#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

bool checkeach(vector<vector<int>> tree1, vector<vector<int>> tree2, int n)
{
    for(int i=1; i<=n; i++)
    {
        if(tree1[i].size() != tree2[i].size())
            return false;
        else
        {
            for(int j=0; j<tree1[i].size(); j++)
            {
                if(tree1[i][j] != tree2[i][j])
                    return false;
            }
        }
    }
    return true;
}

void solve()
{
	int n=0;
	cin>>n;
	
	int e=0;
	cin>>e;
	
	vector<vector<int>> tree1(n+1);
	vector<vector<int>> tree2(n+1);
	
	for(int i=0; i<e; i++)
    {
        int temp1, temp2;
        cin>>temp1>>temp2;
        
        tree1[temp1].push_back(temp2);
    }
    
    for(int i=0; i<e; i++)
    {
        int temp1, temp2;
        cin>>temp1>>temp2;
        
        tree2[temp1].push_back(temp2);
    }
    
    for(int i=1; i<=n; i++)
    {
        if(tree1[i].size() > 1)
        {
            reverse(tree1[i].begin(), tree1[i].end());
        }
    }
    
    cout<<checkeach(tree1,tree2, n)<<endl;
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