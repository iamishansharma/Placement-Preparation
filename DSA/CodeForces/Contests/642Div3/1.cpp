#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

void solve()
{
	int n=0, k=0;
	cin>>n>>k;

	vector<int> a(n);
	vector<int> b(n);

	for(int i=0; i<n; i++)
		cin>>a[i];

	for(int i=0; i<n; i++)
		cin>>b[i];

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	reverse(b.begin(),b.end());

	int ai = 0;
	int bi = 0;

	if(a[0] >= b[0] || k == 0)
	{
		int sum = 0;

		for(int i=0; i<n; i++)
			sum += a[i];

		cout<<sum<<endl;
	}
	else
	{
		int flag = 0;

		int j=0;

		while(k > 0 && flag == 0)
		{
			if(a[j] < b[j])
			{
				int temp = a[j];
				a[j] = b[j];
				b[j] = a[j];
				k--;
				j++;
			}
			else
			{
				flag = 1;
			}
		}

		int sum = 0;

		for(int i=0; i<n; i++)
			sum += a[i];

		cout<<sum<<endl;
	}
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