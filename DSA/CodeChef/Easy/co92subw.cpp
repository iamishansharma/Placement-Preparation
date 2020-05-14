#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

void solve()
{
	int x=0;
	cin>>x;

	vector<int> subways;

	int sum = 1;

	int i=1;

	subways.push_back(1);

	while(sum <= x)
	{
		sum += i+1;
		subways.push_back(sum);
		i++;
	}

	int answer = 0;

	int lower = lower_bound(subways.begin(),subways.end(),x) - subways.begin();
	int upper = upper_bound(subways.begin(),subways.end(),x)- subways.begin();

	/*for(int k=0; k<subways.size(); k++)
	{
		cout<<subways[k]<<" ";
	}
	cout<<endl;*/

	if(subways[lower] == x)
	{
		cout<<lower+1<<endl;
	}
	else if(subways[lower] > x)
	{
		lower--;

		//cout<<"Lower: "<<lower<<" Upper: "<<upper<<endl;

		int uppar = upper+1 + subways[upper] - x;
		int niche = lower+1 + x - subways[lower];

		answer = min(uppar,niche);

		cout<<answer<<endl;
	}	
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