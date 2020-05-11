#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

void solve()
{
	int n = 0;

	cin>>n;

	vector<int> v(2*n);
	
	for(int i=0; i<v.size(); i++)
		cin>>v[i];

	sort(v.begin(),v.end());
	
	vector<int> chote(n);
	vector<int> bade(n);

	for(int i=0; i<n; i++)
		chote[i] = v[i];

	for(int i=n; i<2*n; i++)
		bade[i-n] = v[i];

	int j = 0, k = 0;

	for(int i=0; i<2*n; i++)
	{
		if(i%2 == 0)
			v[i] = chote[j++];
		else
			v[i] = bade[k++];
	}

	cout<<bade[(bade.size()+1)/2 - 1]<<endl;

	for(int i=0; i<2*n; i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
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