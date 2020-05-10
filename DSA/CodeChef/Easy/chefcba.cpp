#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

void solve()
{
	vector<int> array(4);
	cin>>array[0]>>array[1]>>array[2]>>array[3];
	sort(array.begin(),array.end());

	float left = (float)array[0]/(float)array[1];
	float right = (float)array[2]/(float)array[3];

	if(left == right)
		cout<<"Possible"<<endl;
	else
		cout<<"Impossible"<<endl;
}

int main()
{
	fastIO;
	solve();
	return 0;
}