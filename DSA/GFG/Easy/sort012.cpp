#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

void solve()
{
	int n;
	cin>>n;
	
	vector<int> answer(n);
	
	map<int,int> m;
	
	for(int i=0; i<n; i++)
	{
	    cin>>answer[i];
	    m[answer[i]]++;
	}
    
    int i=0;
    
    while(m[0]>0)
    {
        answer[i++] = 0;
        m[0]--;
    }
    
    while(m[1]>0)
    {
        answer[i++] = 1;
        m[1]--;
    }
    
    while(m[2]>0)
    {
        answer[i++] = 2;
        m[2]--;
    }
    
    for(int i=0; i<n; i++)
	{
	    cout<<answer[i]<<" ";
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