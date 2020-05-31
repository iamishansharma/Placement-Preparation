#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

void solve()
{
	string str;
    cin>>str;
    
    stack<int>s;
    
    s.push(-1);
    
    int max1=0;
    
    for(int i=0; i<str.length(); i++)
    {
        if(str[i]=='(')
            s.push(i);
            
        else if(str[s.top()]=='(')
        {
            s.pop();
            max1 = max(max1, i-s.top());
        }
        else
        {
            s.push(i);
        }
    }
    cout<<max1<<endl;
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