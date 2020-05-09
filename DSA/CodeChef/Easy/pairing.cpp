#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

void solve()
{
	int n=0,m=0;
	cin>>n>>m;

	vector<vector<int>> pairs(m, vector<int> (2));

	for(int i=0; i<m; i++)
	{
		cin>>pairs[i][0]>>pairs[i][1];
	}

	vector<int> answer;

	map<int,int> done;
	done.clear();

	for(int i = m-1; i>=0; i--)
	{
		if(done[pairs[i][0]] == 0 && done[pairs[i][1]] == 0)
		{
			answer.push_back(i);
			done[pairs[i][0]] = 1;
			done[pairs[i][1]] = 1;
		}
	}

	sort(answer.begin(),answer.end());

	for(int i=0; i<answer.size(); i++)
	{
		cout<<answer[i]<<" ";
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