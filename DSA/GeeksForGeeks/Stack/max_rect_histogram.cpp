#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
using namespace std;

void solve()
{
	long long int n,area,max=0,i,tp;
    cin>>n;
    
    long long int a[n];
    
    stack<long long int> s;
    
    for(i=0;i<n;i++)
        cin>>a[i];
        
    i=0;

    while(i<n)
    {
        if(s.empty() || a[s.top()] <= a[i])
            s.push(i++);
        else
        {
            tp = s.top(); 
            s.pop();
            area = a[tp] * ((s.empty()) ? i : (i-s.top()-1));

            if(area > max) 
                max = area;
        }
    }

    while(!s.empty())
    {
        tp=s.top(); 
        s.pop();
        area = a[tp] * ((s.empty()) ? i:(i-s.top()-1));
        
        if(area>max) 
            max=area;
    }
    cout<<max<<endl;
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