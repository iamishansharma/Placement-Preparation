#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

void solve()
{
	int n;
	cin >> n;
	int arr[n][n];
	int dum[n][n];
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			cin >> arr[i][j];
			dum[i][j] = arr[i][j];
		}

		int minR = *min_element(arr[i], arr[i] + n);

		for(int j = 0 ; j < n ; j++)
		{
			dum[i][j] -= minR;
		}
	}

	int flag = 0;

	for(int i = 0 ; i < n ;i++)
	{
		int minC = INT_MAX;

		for(int j = 0 ; j < n ; j++)
			if(dum[j][i] < minC)
				minC = dum[j][i];

		for(int j = 0 ; j < n ; j++)
			dum[j][i] -= minC;

		for(int j = 0 ; j < n ; j++)
			if(arr[j][i] != dum[j][i])
			{
				flag = 1;
				break;
			}

		if(flag == 1)
			break;
	}
	if(flag == 1)
		cout << "NO" << "\n";
	else
		cout << "YES" << "\n";
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