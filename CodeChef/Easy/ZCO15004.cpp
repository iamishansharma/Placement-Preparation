#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	pair<int,int> arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].first>>arr[i].second;
	}
	sort(arr,arr+n);
	int rb[n],lb[n];
	stack<pair<int,int>> s;
	
	for(int i=0;i<n;i++)
	{
		while(!s.empty() && s.top().first>arr[i].second)
		{
			pair<int,int> ele=s.top();
			s.pop();
			rb[ele.second]=arr[i].first;
		}
		s.push(make_pair(arr[i].second,i));
	}
	while(!s.empty() )
	{
		pair<int,int> ele=s.top();
		s.pop();
		rb[ele.second]=100000;
	}
	for(int i=n-1;i>=0;i--)
	{
		while(!s.empty() && s.top().first>arr[i].second)
		{
			pair<int,int> ele=s.top();
			s.pop();
			lb[ele.second]=arr[i].first;
		}
		s.push(make_pair(arr[i].second,i));
	}
	while(!s.empty())
	{
		pair<int,int> ele=s.top();
		s.pop();
		lb[ele.second]=0;
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int dist=rb[i]-lb[i];
		ans=max(ans,dist*arr[i].second);
	}
	ans=max(ans,500*arr[0].first);
	for(int i=0;i<n-1;i++)
	{
		ans=max(ans,(arr[i+1].first-arr[i].first)*500);
	}
	ans=max(ans,(100000-arr[n-1].first)*500);
	cout<<ans;
	return 0;
}