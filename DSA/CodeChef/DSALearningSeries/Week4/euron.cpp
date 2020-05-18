#include <bits/stdc++.h>
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int
using namespace std;

long merge(long arr[], long l,long m,long r)
{
	long i  = 0, j = 0, k = 0;
	long n1 = m - l + 1;
	long n2 = r - m;
	long L[n1],R[n2];
	long count = 0;

	for(i = 0; i < n1;i++)
		L[i] = arr[i + l];

	for(j = 0;j < n2;j++)
		R[j] = arr[m + j + 1];

	i = 0;
	j = 0;
	k = l;

	while(i < n1 && j < n2)
	{
		if(L[i] <= R[j])
			arr[k++] = L[i++];
		else
		{
			arr[k++] = R[j++];
			long xc = sizeof(L)/sizeof(L[0]);
			count = count + xc - i;
		}
	}
	
	while(i < n1)
		arr[k++] = L[i++];
	while(j < n2)
		arr[k++] = R[j++];

	return count;
}

long mergesort(long arr[],long l,long r)
{
	long invcount = 0;

	if(r > l)
	{
		long m = l + (r - l)/2;
		invcount += mergesort(arr,l,m);
		invcount += mergesort(arr,m+1,r);
		invcount += merge(arr,l,m,r);
	}
	return invcount;
}

void solve()
{
	long n;
	cin>>n;

	long arr[n];

	for(long i = 0; i < n; i++)
	{
		long r;
		cin>>r;
		arr[i] = r;
	}

	long arr_size = sizeof(arr)/sizeof(arr[0]);

	cout<<mergesort(arr,0,arr_size)<<endl;
}

int main()
{
	fastIO;

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout); 
	#endif
	
	solve();
	return 0;
}