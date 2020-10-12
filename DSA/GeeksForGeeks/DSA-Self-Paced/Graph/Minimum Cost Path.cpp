// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int shortest(vector<vector<int>> &grid, int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<int>> grid(n);

        for (int i = 0; i < n; i++)
        {
            grid[i].resize(n);
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }

        cout << shortest(grid, n) << endl;
    }
    return 0;
}
// } Driver Code Ends

// User function template for C++

// grid : given n*n grid
// n : size of the square grid
typedef pair<int, pair<int, int>> custompair;

int shortest(vector<vector<int>> &grid, int n)
{
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    dist[0][0] = grid[0][0];

    priority_queue<custompair, vector<custompair>, greater<custompair>> pq;

    pq.push({dist[0][0], {0, 0}});

    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};

    while (!pq.empty())
    {
        custompair temp = pq.top();
        pq.pop();

        int distu = temp.first;
        int x = temp.second.first;
        int y = temp.second.second;

        for (int i = 0; i < dx.size(); i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];

            if (newx >= 0 && newy >= 0 && newx < n && newy < n && dist[newx][newy] > distu + grid[newx][newy])
            {
                dist[newx][newy] = distu + grid[newx][newy];
                pq.push({dist[newx][newy], {newx, newy}});
            }
        }
    }

    return dist[n - 1][n - 1];
}