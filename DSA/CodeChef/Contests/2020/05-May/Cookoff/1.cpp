#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	ll n=0;
	cin>>n;

	vector<ll> v(n);
	
	for(int i=0; i<v.size(); i++)
		cin>>v[i];
	
	/*

	{

		map<int,int> m;

		int flag = 0;

		for(int i=0; i<n; i++)
		{
			//cout<<i<<endl;
			if(i == 0)
			{
				if(v[i] == v[i+1])
				{
					m[v[i]] += 1;
				}
				else
				{
					if(m[v[i]] != 0)
					{
						flag = 1;
					}
					else
						m[v[i]] += 1;
				}
			}
			else if(i == n-1)
			{
				if(v[i] == v[i-1])
				{
					m[v[i]] += 1;
				}
				else
				{
					if(m[v[i]] != 0)
					{
						flag = 1;
					}
					else
						m[v[i]] += 1;
				}
			}
			else
			{
				if(v[i] == v[i-1] || v[i] == v[i+1])
				{
					m[v[i]] += 1;
				}
				else
				{
					if(m[v[i]] != 0)
					{
						flag = 1;
					}
					else
						m[v[i]] += 1;
				}
			}
		}

		if(flag == 0)
		{
			int flag2 = 0;

			map<int,int> num;
			num.clear();

			for(auto const& pair:m)
			{
				if(num[pair.second] == 1)
				{
					flag2 = 1;
				}
				else
				{
					num[pair.second] = 1;
				}
			}
			
			if(flag2 == 1)
				cout<<"NO"<<endl;
			else
				cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}

	}

	*/

	int flag = 0;

	map<ll,ll> m;
	m.clear();

	for(ll i=0; i<n; i++)
	{
		if(i == 0)
		{
			m[v[i]]++;
		}
		else if(i == n-1)
		{
			if(v[i] != v[i-1])
			{
				if(m[v[i]] != 0)
				{
					flag = 1;
				}
				else
					m[v[i]]++;
			}
			else
			{
				m[v[i]]++;
			}
		}
		else
		{
			if(v[i] != v[i-1] && v[i] != v[i+1])
			{
				if(m[v[i]] != 0)
				{
					flag = 1;
				}
				else
					m[v[i]]++;
			}
			else
			{
				m[v[i]]++;
			}
		}
	}

	if(flag == 1)
	{
		cout<<"NO"<<endl;
	}
	else
	{
		map<ll,ll> nums;
		nums.clear();

		int flag2 = 0;

		for(auto const& pair:m)
		{
			if(nums[pair.second] == 0)
			{
				nums[pair.second]++;
			}
			else
			{
				flag2 = 1;
				nums[pair.second]++;
			}
		}

		map<ll,ll> nums2;
		nums2.clear();

		int flag3 = 0;

		for(auto const& pair:m)
		{
			if(nums2[pair.first] == 0)
			{
				nums2[pair.first]++;
			}
			else
			{
				flag3 = 1;
				nums2[pair.first]++;
			}
		}

		/*for(auto const& pair:nums)
		{
			cout<<"{"<<pair.first<<", "<<pair.second<<"}\n";
		}*/

		if(flag2 == 0 && flag3 == 0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}

int main()
{
	fastIO;

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout); 
	#endif
	
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
	return 0;
}