#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

void solve()
{
	string str;
	cin>>str;

	set<char> s;

	for (auto i = str.begin();i != str.end();i++) 
		s.insert(*i);

	int n = str.length();
	int count = 0;

	//cout<<"Debuging: "<<endl;

	for (int i = 0; i < n; i++)
	{
		//cout<<"Str: "<<str[i];

		//cout<<endl<<"Set: ";

		/*for(auto k=s.begin(); k!=s.end(); k++)
		{
			cout<<*k<<" ";
		}*/

		//cout<<endl;

		if(s.find(str[i]) == s.end())
			continue;
		else
		{
			count++;
			s.erase(str[i]);
		}
	}
	
	cout << count << endl;
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