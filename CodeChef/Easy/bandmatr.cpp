#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int N,key,zeros,k;
	cin>>N;
	zeros=0;
	for(int i=0;i<N*N;i++)
	{
		cin>>key;
		if(key==0)
			zeros++;
	}
	for(k=0; k<N; k++)
		if(zeros >= (N-k)*(N-k-1))
			break;
	cout<<k<<endl;	
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