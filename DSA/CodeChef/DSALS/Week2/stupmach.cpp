#include <bits/stdc++.h>
using namespace std;

void solve()
{
	long long int n,sub=0;
	cin>>n;
	vector<long long int> v(n);
	
	for(int i=0; i<v.size(); i++)
		cin>>v[i];
	
	long long int sum=0;

	while(v.size() != 0)
	{
		long long minvalue = *min_element(v.begin(),v.end());
		vector<long long>::iterator it;
		it = find(v.begin(),v.end(),minvalue);
		long long start = it - v.begin();
		long long mul = minvalue - sub;
		sum += mul*v.size();
		v.erase(v.begin()+start,v.end());
		sub = minvalue;
	}

	cout<<sum<<endl;
}

int main()
{
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
	return 0;
}