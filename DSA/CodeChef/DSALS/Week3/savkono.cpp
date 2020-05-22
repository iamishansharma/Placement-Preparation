#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

void solve()
{
	int n=0,z=0;
	cin>>n>>z;

	vector<int> v(n);
	
	for(int i=0; i<v.size(); i++)
		cin>>v[i];
	
	priority_queue<int> pq;

	for(int i=0;i<n;i++)
		pq.push(v[i]);

	int answer = 0;

	while(z>0 && pq.top()>0)
	{
		int maxsol = pq.top();
		z -= maxsol;

		pq.pop();
		pq.push(maxsol/2);

		answer++;
	}

	if(z>0)
		cout<<"Evacuate"<<endl;
	else
		cout<<answer<<endl;
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