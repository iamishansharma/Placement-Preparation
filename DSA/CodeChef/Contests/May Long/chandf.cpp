#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long int ll;
using namespace std;

ll F(ll x, ll y, ll z)
{
	return (x&z)*(y&z);
}

void solve()
{
	int x = 0, y = 0, l = 0, r = 0;

	cin>>x>>y>>l>>r;

	if(l<=x && r<=x)
	{
		cout<<r<<endl;
	}
	else if(l>=x && r<=y)
	{
		if(l == x && r != y)
		{
			cout<<l<<endl;
		}
		else
		{
			cout<<r<<endl;
		}
	}
	else
	{
		ll maxval = -1;
		ll index = -1;

		for(int i=l; i<=r; i++)
		{
			if(F(x,y,i) > maxval)
			{
				maxval = F(x,y,i);
				index = i;
			}
		}

		cout<<index<<endl;

		ll n=index;

		ll binaryNum[128];
  
	    // counter for binary array 
	    int i = 0; 
	    while (n > 0) 
	    {
	        // storing remainder in binary array 
	        binaryNum[i] = n % 2; 
	        n = n / 2; 
	        i++; 
	    } 
	  
	    // printing binary array in reverse order 
	    for (int j = i - 1; j >= 0; j--) 
	        cout << binaryNum[j];

	    cout<<endl;
	}
}

int main()
{
	/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif*/
	fastIO;
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
	return 0;
}