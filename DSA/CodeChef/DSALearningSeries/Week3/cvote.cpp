#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

void solve()
{
	int n=0,m=0;
	cin>>n>>m;

	map<string,string> ent;

	for(int i=0; i<n; i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		ent[s1] = s2;
	}

	map<string,int> votes;
	map<string,int> votescont;

	string maxcountry;
	string maxchef;

	int maxcountryvotes = 0;
	int maxchefvotes = 0;

	for(int i = 0; i<m; i++)
	{
		string chef;
		cin>>chef;

		votes[chef]++;

		votescont[ent[chef]]++;

		if(votes[chef] > maxchefvotes)
		{
			maxchef = chef;
			maxchefvotes = votes[chef];
		}
		else if(votes[chef] == maxchefvotes)
		{
			maxchef = min(chef, maxchef);
		}
		if(votescont[ent[chef]] > maxcountryvotes)
		{
			maxcountry = ent[chef];
			maxcountryvotes = votescont[ent[chef]];
		}
		else if(votescont[ent[chef]] == maxcountryvotes)
		{
			maxcountry = min(ent[chef], maxcountry);
		}
	}
	cout<<maxcountry<<endl;
	cout<<maxchef<<endl;
}

int main()
{
	fastIO;
	solve();
	return 0;
}