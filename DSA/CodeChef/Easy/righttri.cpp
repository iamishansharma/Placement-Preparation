#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

void solve()
{
	int n=0;

	cin>>n;

	int answer = 0;

	for(int i=0; i<n; i++)
	{
		int x1,x2,x3,y1,y2,y3;

		cin>>x1>>y1>>x2>>y2>>x3>>y3;

		int a=0;
		int b=0;
		int c=0;

		a = pow((x3-x1),2) + pow((y3-y1),2);
		b = pow((x2-x3),2) + pow((y2-y3),2);
		c = pow((x2-x1),2) + pow((y2-y1),2);

		if(c == a + b)
			answer++;
		else if(a == b + c)
			answer++;
		else if(b == a + c)
			answer++;
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