// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}// } Driver Code Ends


/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/
/*

// Recursive DFS

void DFS(vector<int>A[], int i, int j, vector<vector<bool>>&visited, int n, int m)
{
    if(i<0 || j<0 || i>=n || j>=m || A[i][j]==0 || visited[i][j]==true)
        return;
        
    visited[i][j] = true;
    
    DFS(A,i+1,j,visited,n,m);
    DFS(A,i,j+1,visited,n,m);
    DFS(A,i-1,j,visited,n,m);
    DFS(A,i,j-1,visited,n,m);
    DFS(A,i+1,j+1,visited,n,m);
    DFS(A,i+1,j-1,visited,n,m);
    DFS(A,i-1,j+1,visited,n,m);
    DFS(A,i-1,j-1,visited,n,m);
}
int findIslands(vector<int> A[], int n, int m) 
{
    int i,j;
    int count=0;
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(A[i][j]==1 && visited[i][j]==false)
            {
                DFS(A,i,j,visited,n,m);
                count++;
            }
        }
    }
    return count;
}*/

// Iterative BFS ->

bool inBounds(int i, int j, vector<int> A[], vector<vector<bool>> &visited, int n, int m)
{
    return (i >= 0 && j >= 0 && i < n && j < m && A[i][j] == 1 && visited[i][j] == false);
}

void BFS(int s1, int s2, vector<int> A[], vector<vector<bool>> &visited, int n, int m)
{
    queue<pair<int,int>> q;
    q.push({s1,s2});
    visited[s1][s2] = true;
    
    int row[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int col[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    
    while(!q.empty())
    {
        pair<int,int> f = q.front();
        q.pop();
        
        for(int k=0; k<8; k++)
            if(inBounds(f.first + row[k], f.second + col[k], A, visited, n, m))
            {
                visited[f.first + row[k]][f.second + col[k]] = true;
                q.push({f.first + row[k],f.second + col[k]});
            }
    }
}

int findIslands(vector<int> A[], int n, int m) 
{
    vector<vector<bool>> visited(n, vector<bool> (m));
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            visited[i][j] = false;
    
    int ans = 0;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(A[i][j] == 1 && visited[i][j] == false)
            {
                ans++;
                BFS(i,j,A,visited,n,m);
            }
        }
    }
    
    return ans;
}