#include <bits/stdc++.h>
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int
using namespace std;

void solve()
{
	int x,b,c;
	cin >> x >> b;
	priority_queue<pair<int, pair<int, pair<long long, long long>>>> pq;
	
	for(int i=0;i<b;i++)
	{
		int xi;
		long long y;
		cin >> xi >> y;
		pq.push({xi,{0, {y,0}}});
	}
	cin >> c;

	for(int i=0;i<c;i++)
	{
		int p;
		long long q,r;
		cin >> p >> q >> r;
		pq.push({p, {1, {q, r}}});
	}

	long long req = 1;

	while (!pq.empty())
	{
		pair<int, pair<int, pair<long long, long long>>> top = pq.top();

		pq.pop();

		if(top.second.first)
		{
			long long qi = top.second.second.first;
			long long ri = top.second.second.second;

			if(qi < req)
			{
				if(qi + ri < req)
				{
					req -= ri;
				}
				else
				{
					req = qi;
				}
			}
		}
		else
		{
			req += top.second.second.first;
		}
	}
	cout << req << endl;
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