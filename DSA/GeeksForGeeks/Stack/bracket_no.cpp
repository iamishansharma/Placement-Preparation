#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

void solve()
{
    int count=0,n;
    
    string exp;
    cin>>exp;
    
    stack<int> S;
    
    for(int i=0;i<exp.length();i++)
    {
        if(exp[i]=='(')
        {
            count++;
            cout<<count<<" ";
            S.push(count);
        }
        else if(exp[i]==')')
        {
            n=S.top();
            cout<<n<<" ";
            S.pop();
        }
        else
            continue;
    }
    cout<<"\n";
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