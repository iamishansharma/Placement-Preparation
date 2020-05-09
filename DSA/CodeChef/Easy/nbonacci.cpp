#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

int main() 
{
	int n, q, x;
	unsigned long long int hat=0;
	cin >> n >> q;
	int temp[n+1];
	unsigned long long int ans[n+1];
	ans[0] = 0;
	for(int i=1;i<n+1;i++)
	{
	    cin >> x;
	    temp[i] = x;
	    ans[i] = ans[i-1]^x;
	}
	n++;
	while(q--)
	{
	    cin >> x;
	    cout << ans[x%(n)] << endl;
	}
	
}
