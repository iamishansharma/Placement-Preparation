#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

int PerformOperation(char op,int op1,int op2)
{
    if(op=='+') return op1+op2;
    else if(op=='-') return op1-op2;
    else if(op=='*') return op1*op2;
    else if(op=='/') return op1/op2;
}

void solve()
{
    string exp;
    cin>>exp;
    
    stack<int> S;
    for(int i=0;i<exp.length();i++)
    { 
        if(exp[i] >= '0' && exp[i] <= '9')
            S.push(exp[i]-'0');
            
        else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/')
        {
            int op2=S.top(); 
            S.pop();
            int op1=S.top(); 
            S.pop();
            int res=PerformOperation(exp[i],op1,op2);
            S.push(res);
        }
    }
    cout<<S.top()<<endl;
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