#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

void solve()
{
	int N;
	cin >> N;
	int count = 0;
	vector<int> A(N+1);
	for (int i = 1; i <= N; i++) 
		cin >> A[i];

	for (int i = 1; i <= N; i++) 
	{
		if(i > 1)
		{
			if(A[i] != A[i - 1])
			{
				count++;
				continue;
			}
		}	
		if(i < N)
			if(A[i] != A[i + 1])
				count++;
	}
	cout << count << '\n';
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