// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/* Function to do DFS of graph
*  g[]: array of vectors to represent graph
*  vis[]: array to keep track of visited vertex
*/
void dfs(int s, vector<int> g[], bool vis[])
{
    ///*

    // Recursive Approach

    vis[s] = true;

    cout<<s<<" ";

    for(vector<int>::iterator i = g[s].begin(); i!=g[s].end(); ++i)
    {
        if(!vis[*i])
            dfs(*i, g, vis);
    }

    //*/

    /*

    // Iterative Approach ->

    stack<int> st;
    st.push(s);
    cout<<s<<" ";
    vis[s]=1;
    while(!st.empty())
    {
        int top = st.top();

        int flag = 0; // flag is used for back tracking, if the 'top' 
                      // has no adjacent nodes left pop it will some top has adjacent nodes. NICE

        for(int i=0; i<g[top].size(); i++)
        {
            if(!vis[g[top][i]])
            {
                st.push(g[top][i]);

                cout<<g[top][i]<<" ";

                vis[g[top][i]] = 1;

                flag = 1;

                break;
            }
        }

        if(!flag) 
            st.pop();
    }

    */
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(0,g,vis);
        
        cout<<endl;

    }
}  // } Driver Code Ends