#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

void solve()
{
	int k;
	cin>>k;
    ll div,rem,num;
    num = 103993;
    ll i=0;
    while(i<=k)
    {
        if(i==1)
        {
            cout<<".";
        }
        div = num/33102;
        cout<<div;
        rem = num % 33102;
        num = rem * 10;
        if(num < 33102)
        {
            num = rem*10;
        }
        i++;
    }
    cout<<endl;
}

int main()
{
	fastIO;

	/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif*/
	
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
	return 0;
}