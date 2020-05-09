#include <bits/stdc++.h>
using namespace std;

map<string,int> points, goals;

bool cmp(const string &a , const string &b)
{
    if(points[a] > points[b]) return 1;
    if(points[a] < points[b]) return 0;
    if(goals[a] > goals[b]) return 1;
    return 0;
}

int main()
{
	int tc=0;
	cin>>tc;
	string team1,vs,team2;
	int g1, g2;
	set < string > teams;
	while(tc--)
	{
		points.clear();
		goals.clear();

		for(int i=0; i<12; i++)
		{
			cin>>team1>>g1>>vs>>g2>>team2;

			if(g1>g2)
			{
				points[team1] += 3;
				points[team2] += 0;
			}
			else if(g1<g2)
			{
				points[team2] += 3;
				points[team1] += 0;
			}
			else
			{
				points[team2] += 1;
				points[team1] += 1;
			}

			goals[team1] += (g1-g2);
			goals[team2] += (g2-g1);

			teams.insert(team1);
            teams.insert(team2);
		}

		vector<string> v(teams.begin() , teams.end());
        sort(v.begin() , v.end() , cmp);
        cout<<v[0]<<' '<<v[1]<<endl;
	}
	return 0;
}