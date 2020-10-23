// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

/* This function does union of 2 nodes a and b */
// a : node 1
// b : node 2
// par : empty array (n+1) size with all elements as i
// rank1 : empty array (n+1) size with all elements as 1
int find(int x, int parent[])
{
    if (parent[x] == x)
        return x;
    else
        parent[x] = find(parent[x], parent);
}

void union_(int a, int b, int par[], int rank[])
{
    int fa = find(a, par);
    int fb = find(b, par);

    if (fa == fb)
        return;

    if (rank[a] < rank[b])
    {
        par[fa] = par[fb];
        rank[fb]++;
    }
    else
    {
        par[fb] = par[fa];
        rank[fa]++;
    }
}

/* This function checks whether 2 nodes x and y are connected or not */
// x : node 1
// y : node 2
// par : empty array (n+1) size with all elements as i
// rank1 : empty array (n+1) size with all elements as 1
bool isConnected(int x, int y, int par[], int rank1[])
{
    return find(x, par) == find(y, par);
}

// { Driver Code Starts.

int main()
{
    //taking number of testcases
    int t;
    cin >> t;
    while (t--)
    {

        //taking number of elements
        int n;
        cin >> n;

        int par[n + 1];
        int rank1[n + 1];

        //initializing the parent and
        //the rank array
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
            rank1[i] = 1;
        }

        //taking number of queries
        int q;
        cin >> q;
        while (q--)
        {
            int a, b;
            char c;
            cin >> c >> a >> b;

            //if query type is 'U'
            //then calling union_ method
            if (c == 'U')
            {
                union_(a, b, par, rank1);
            }
            else //else calling isConnected() method
                cout << isConnected(a, b, par, rank1) << endl;
        }
    }
    return 0;
}
// } Driver Code Ends