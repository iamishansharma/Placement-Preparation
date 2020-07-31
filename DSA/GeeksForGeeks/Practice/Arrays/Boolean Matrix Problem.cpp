#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void boolMatrixProblem(vector<vector<int>> &mat, int n, int m)
{
    vector<bool> row(n);
    vector<bool> col(m);
    
    for(int i=0; i<n; i++)
        row[i] = false;
    
    for(int j=0; j<m; j++)
        col[j] = false;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(mat[i][j] == 1)
                row[i] = true, col[j] = true;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(row[i] || col[j])
                mat[i][j] = 1;
}

void solve()
{
	int n=0;
	cin>>n;
	
	int m=0;
	cin>>m;
	
	vector<vector<int>> mat(n, vector<int> (m));
	
	for(int i=0; i<n; i++)
	    for(int j=0; j<m; j++)
	        cin>>mat[i][j];
	        
    boolMatrixProblem(mat, n, m);
    
    for(int i=0; i<n; i++)
    {
	    for(int j=0; j<m; j++)
	        cout<<mat[i][j]<<" ";
	    cout<<endl;
    }
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