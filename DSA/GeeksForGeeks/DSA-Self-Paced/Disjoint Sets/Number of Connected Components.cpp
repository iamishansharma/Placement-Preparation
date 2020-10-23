// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;

int arr[100001];
int rank1[100001];

// } Driver Code Ends

//User function Template for C++

/* This function does union of 2 nodes a and b */
// a : node 1
// b : node 2
// arr : array (n+1) size with elements from 1 to N equal to its index.
// rank1 : array (n+1) size with all elements equal to 1.
// n : Number of nodes
int find(int x, int parent[])
{
    if (x == parent[x])
        return x;
    else
        return parent[x] = find(parent[x], parent);
}

void unionNodes(int a, int b, int parent[], int rank[], int n)
{
    int fa = find(a, parent);
    int fb = find(b, parent);

    if (fa == fb)
        return;

    if (rank[fa] < rank[fb])
    {
        parent[fa] = fb;
        rank[fb]++;
    }
    else
    {
        parent[fb] = fa;
        rank[fa]++;
    }
}

/* This function returns number of connected components */
// arr : array (n+1) size with elements from 1 to N equal to its index.
// rank1 : array (n+1) size with all elements equal to 1.
// n : Number of nodes
int findNumberOfConnectedComponents(int n, int parent[], int rank[])
{
    int ans = 0;

    for (int i = 1; i <= n; i++)
        ans += parent[i] == i ? 1 : 0;

    return ans;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {

        //taking number of nodes
        int n;
        cin >> n;

        //initializing parent array and
        //rank array
        for (int i = 1; i <= n; i++)
        {
            arr[i] = i;
            rank1[i] = 1;
        }

        //taking number of queries
        int q;
        cin >> q;
        while (q--)
        {
            int a, b;
            cin >> a >> b;

            //calling unionNodes() function
            unionNodes(a, b, arr, rank1, n);
        }

        //calling function findNumberofConnectedComponents()
        cout << findNumberOfConnectedComponents(n, arr, rank1) << endl;
    }
    return 0;
} // } Driver Code Ends