#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main()
{
	long long N,K,i,j;
	cin>>N>>K;
	long long A[N],f=1;
	for(i=0;i<N;i++)
	{
	    cin>>A[i];
	}
	stack <pair<int,int>> st;
	i=0;
	for(i=N-1;i>=0;i--)
	{
	    if(st.empty())
	        st.push(make_pair(i,A[i]));

	    else if(A[i] > st.top().second)
	    {
	        f=(f*(st.top().first-i+1))%MOD;
	        st.push(make_pair(i,A[i]));
	    }

	    else if(A[i] <= st.top().second)
	    {
	        while(!st.empty() && st.top().second>=A[i])
	            st.pop();

	        if(!st.empty())
	            f=(f*(st.top().first-i+1))%MOD;

	        st.push(make_pair(i,A[i]));
	    }
	}
	cout<<f<<endl;
	return 0;
}