#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int


void solve()
{
	int n = 0;
	cin>>n;

	int mat[n][n];

	for(int i=0; i<n; i++)
	{
		string s;
		cin>>s;

		for(int j=0; j<n; j++)
		{
			if(s[j] == '1')
				mat[i][j] = 1;
			else
				mat[i][j] = 0;
		}
	}

	int flag = 0;

	int flag2 = 0;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(mat[i][j] == 1)
			{
				if(i == 0)
				{
					if(j == 0)
					{
						if(mat[i+1][j] == 1 || mat[i][j+1] == 1)
						{
							;
						}
						else
						{
							flag = 1;
						}
					}
					else
					{
						if(mat[i+1][j] == 1 || mat[i][j+1] == 1 || mat[i][j-1] == 1)
						{
							;
						}
						else
						{
							flag = 1;
						}
					}
				}
				else if(i == n-1)
				{
					if(j == 0)
					{
						if(mat[i-1][j] == 1 || mat[i][j+1] == 1)
						{
							;
						}
						else
						{
							flag = 1;
						}
					}
					else if(j == n-1)
					{
						if(mat[i][j-1] == 1 || mat[i+1][j] == 1)
						{
							;
						}
						else
						{
							flag = 1;
						}
					}
					else
					{
						if(mat[i-1][j] == 1 || mat[i][j+1] == 1 || mat[i][j-1] == 1)
						{
							;
						}
						else
						{
							flag = 1;
						}
					}
				}
				else if(j == 0)
				{
					if(i == 0)
					{
						if(mat[i+1][j] == 1 || mat[i][j+1] == 1)
						{
							;
						}
						else
						{
							flag = 1;
						}
					}
					else
					{
						if(mat[i+1][j] == 1 || mat[i][j+1] == 1 || mat[i-1][j] == 1)
						{
							;
						}
						else
						{
							flag = 1;
						}
					}
				}
				else if(j == n-1)
				{
					if(i == 0)
					{
						if(mat[i+1][j] == 1 || mat[i][j-1] == 1)
						{
							;
						}
						else
						{
							flag = 1;
						}
					}
					else if(i == n-1)
					{
						if(mat[i][j-1] == 1 || mat[i-1][j] == 1)
						{
							;
						}
						else
						{
							flag = 1;
						}
					}
					else
					{
						if(mat[i-1][j] == 1 || mat[i+1][j] == 1 || mat[i][j-1] == 1)
						{
							;
						}
						else
						{
							flag = 1;
						}
					}
				}
				else
				{
					if(mat[i-1][j] == 1 || mat[i+1][j] == 1 || mat[i][j-1] == 1 || mat[i][j+1] == 1)
					{
						;
					}
					else
					{
						flag = 1;
						cout<<i<<j<<endl;
					}
				}
			}

			if(flag == 1)
			{
				flag2 = 1;
				break;
			}

			if(i == 2 && j == 3)
			{
				cout<<"mat: "<<mat[i][j]<<endl;
				cout<<"flag: "<<flag<<endl;
			}
		}
		if(flag2)
			break;
	}

	if(flag)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
}

int main()
{
	fastIO;

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