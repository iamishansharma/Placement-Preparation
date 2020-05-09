#include <bits/stdc++.h>
using namespace std;
#define BOOST_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve()
{
	int i=0;
	long long a,y;
	cin>>a;
	y=a;
	long long sum=0,max;

	int x=2,b=1,dif=0;

	for(i=1;i<=y;i++)
	{ 
		a=y*(i);
		sum=pow(2,i)-1;
		dif=sum-a;
		if(sum > a)
		{
			max=i;
			break;
		}
		if(pow(2,i)<y)
			b++;	 
	}
 	cout<<max-1<<" "<<b<<endl;
}

int main()
{
	BOOST_IO;

	int tc=0;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
	return 0;
}