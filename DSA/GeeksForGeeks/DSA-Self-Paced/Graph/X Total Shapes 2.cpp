#include <bits/stdc++.h>
using namespace std;
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define debug(x)                          \
    {                                     \
        cerr << #x << " = " << x << endl; \
    }
#define ll long long int

void DFS(int i, int j, vector<string> &grid, vector<vector<bool>> &visited, int n, int m)
{
    if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || grid[i][j] != 'X')
        return;

    visited[i][j] = true;

    DFS(i + 1, j, grid, visited, n, m);
    DFS(i - 1, j, grid, visited, n, m);
    DFS(i, j + 1, grid, visited, n, m);
    DFS(i, j - 1, grid, visited, n, m);
}

int xtotalshapes(vector<string> &grid, int n, int m)
{
    int ans = 0;

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'X' && !visited[i][j])
            {
                DFS(i, j, grid, visited, n, m);
                ans++;
            }
        }
    }

    return ans;
}

void solve()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    vector<string> grid(n);

    for (int i = 0; i < n; i++)
        cin >> grid[i];

    cout << xtotalshapes(grid, n, m) << endl;
}

int main()
{
    fastIO;

    int tc = 0;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}