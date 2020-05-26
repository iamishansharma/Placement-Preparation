// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long
queue<ll> modifyQueue(queue<ll> q, int k);
int main(){
    ll t;
    cin>>t;
    while(t-->0){
        ll n,k;
        cin>>n>>k;
        queue<ll> q;
        while(n-->0){
            ll a;
            cin>>a;
            q.push(a);
        }
        queue<ll> ans=modifyQueue(q,k);
        while(!ans.empty()){
            int a=ans.front();
            ans.pop();
            cout<<a<<" ";
        }
        cout<<endl;
    }
}// } Driver Code Ends


//User function Template for C++

queue<ll> modifyQueue(queue<ll> q, int k)
{
    if(q.empty())
        return q;
        
    queue<ll> newq;
    stack<ll> s;
    
    for(int i=1; i<=k; i++)
    {
        s.push(q.front());
        q.pop();
    }
    
    while(!s.empty())
    {
        newq.push(s.top());
        s.pop();
    }
    
    while(!q.empty())
    {
        newq.push(q.front());
        q.pop();
    }
    
    return newq;
}