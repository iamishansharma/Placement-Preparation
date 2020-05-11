#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

int fact(int n) 
{
   if (n == 0 || n == 1)
      return 1;
   else
      return n * fact(n - 1);
}

void solve()
{
	int x,n;
	cin>>x>>n;

	int answer = 0;

	for(int i=0; i<n; i++)
	{
		string s;
		cin>>s;

		vector<int> v(54); 
		v.clear();

		for(int j=0; j<54; j++)
		{
			if(s[j] == '1')
				v[j] = 1;
			else
				v[j] = 0;
		}

		/*cout<<"Initial: "<<endl;

		for(int b=0; b<54; b++)
		{
			cout<<v[b];
		}

		cout<<endl;*/

		vector<vector<int>> seats(9, vector<int> (6));

		for(int aai=0; aai<9; aai++)
			for(int jee=0; jee<6; jee++)
				seats[aai][jee] = -1;

		for(int l=0; l<9; l++)
		{
			int index = 4*l+1;

			seats[l][0] = v[index-1];
			seats[l][1] = v[index+1-1];
			seats[l][2] = v[index+2-1];
			seats[l][3] = v[index+3-1];
			seats[l][4] = v[53-(2*l)-1];
			seats[l][5] = v[53-(2*l)];
		}

		/*cout<<"Compartments: "<<endl;

		for(int aai=0; aai<9; aai++)
		{
			for(int jee=0; jee<6; jee++)
			{
				cout<<seats[aai][jee]<<" ";
			}
			cout<<endl;
		}*/

		vector<map<int,int>> maps(9);

		for(int aai=0; aai<9; aai++)
		{
			for(int jee=0; jee<6; jee++)
			{
				maps[aai][seats[aai][jee]]++;
			}

			/*for(auto const& pair:maps[aai])
			{
				cout<<"{"<<pair.first<<", "<<pair.second<<"} ";
			}

			cout<<endl;*/

			if(maps[aai][0] >= x)
				answer += fact(maps[aai][0])/(fact(x)*fact(maps[aai][0]-x));
		}
	}

	cout<<answer<<endl;
}

int main()
{
	fastIO;
	/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif*/
	solve();
	return 0;
}