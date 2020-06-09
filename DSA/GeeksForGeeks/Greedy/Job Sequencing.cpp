// https://practice.geeksforgeeks.org/problems/job-sequencing-problem/0

#include <bits/stdc++.h>
using namespace std;

class jobs
{
	public:
			int id;
			int d;
			int p;
};

bool comp(jobs a,jobs b)
{
	if(a.p != b.p)
		return a.p>b.p;

	return a.id < b.id;    
}

void solve()
{
	int n;
	cin>>n;

	jobs *arr = new jobs[n];
	bool *slots = new bool[n];

	for(int i=0; i<n; i++)
		slots[i]=false;

	for(int i=0; i<n; i++)
		cin>>arr[i].id>>arr[i].d>>arr[i].p;

	sort(arr, arr+n, comp);

	int profit=0;
	int count=0;

	for(int i=0; i<n; i++)
	{
		for(int j = min(n-1,arr[i].d-1); j>=0; j--)
		{
			if(!slots[j])
			{
				slots[j]=true;
				count++;
				profit += arr[i].p;
				break;
			}
		}
	}
	cout<<count<<" "<<profit<<endl;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}