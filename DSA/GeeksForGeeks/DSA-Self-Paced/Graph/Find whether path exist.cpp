// { Driver Code Starts
#include <bits/stdc++.h>

#define MAX 1000
using namespace std;

bool is_possible(vector<vector<int>> &a, int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<int>> a(MAX, vector<int>(MAX, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];

        cout << is_possible(a, n) << endl;
    }
    return 0;
} // } Driver Code Ends

// User function template for C++

// M : input matrix
// N : size of the matrix
bool DFS(int i, int j, vector<vector<int>> &mat, vector<vector<bool>> &visited, int N)
{
    if (i < 0 || j < 0 || i >= N || j >= N || mat[i][j] == 0 || visited[i][j] == true)
        return false;

    visited[i][j] = true;

    if (mat[i][j] == 2)
        return true;
    else
        return DFS(i + 1, j, mat, visited, N) || DFS(i - 1, j, mat, visited, N) || DFS(i, j + 1, mat, visited, N) || DFS(i, j - 1, mat, visited, N);
}

bool is_possible(vector<vector<int>> &mat, int N)
{
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (mat[i][j] == 1)
            {
                if (DFS(i, j, mat, visited, N))
                    return true;
            }
        }
    }

    return false;
}
