#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	int count=0;
    string exp;
    cin>>exp;
    
    stack<int> s;
    s.push(-1);
    
    for(int i=0;i<exp.length();i++)
    {
        if(exp[i]==')' && !s.empty())
        {
            if(exp[s.top()]=='(')
            {
                s.pop();
                
                if(!s.empty() && (i-s.top()) > count)
                    count=i-s.top();
            }
            else if(!s.empty())
            {
                s.pop();
                s.push(i);
            }
        }
        else
            s.push(i);
    }
    cout<<count<<endl;
}

int main()
{
	fastIO;
	
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
	return 0;
}