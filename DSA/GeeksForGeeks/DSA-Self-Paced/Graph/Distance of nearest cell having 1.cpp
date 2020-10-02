// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

void print(vector<vector<int>> arr, int row, int col)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
    }
    cout << "\n";
}

vector<vector<int>> nearest(vector<vector<int>> &arr, int row, int col);
int main()
{

    int tc;
    cin >> tc;
    while (tc--)
    {
        int row, col;
        cin >> row >> col;

        // Input matrix is represented using vectors of vectors
        vector<vector<int>> graph(row, vector<int>(col, 0));

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> graph[i][j];
            }
        }

        print(nearest(graph, row, col), row, col);
    }

    return 0;
}
// } Driver Code Ends

/*  Function to find the distance of nearest cell having 1

*   mat: The input matrix of 0s and 1s
*   N, M: rows and cols in given matrix
*   Return the resultant matrix of size (N x M) representing the nearest distance 1 from each cell
*/
void bfs(vector<vector<int>> &arr, vector<vector<bool>> &vis, vector<vector<int>> &dist, int row, int col)
{
    queue<pair<int, int>> q;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == 1)
            {
                dist[i][j] = 0;
                vis[i][j] = true;
                q.push(make_pair(i, j));
            }
            else
                dist[i][j] = INT_MAX;
        }
    }

    while (!q.empty())
    {
        pair<int, int> u = q.front();
        q.pop();

        int a = u.first;
        int b = u.second;

        int x = dist[a][b];

        if (a - 1 >= 0 && !vis[a - 1][b])
        {
            vis[a - 1][b] = true;
            dist[a - 1][b] = min(dist[a - 1][b], x + 1);
            q.push(make_pair(a - 1, b));
        }
        if (a + 1 < row && !vis[a + 1][b])
        {
            vis[a + 1][b] = true;
            dist[a + 1][b] = min(dist[a + 1][b], x + 1);
            q.push(make_pair(a + 1, b));
        }
        if (b - 1 >= 0 && !vis[a][b - 1])
        {
            dist[a][b - 1] = min(dist[a][b - 1], x + 1);
            vis[a][b - 1] = true;
            q.push(make_pair(a, b - 1));
        }
        if (b + 1 < col && !vis[a][b + 1])
        {
            dist[a][b + 1] = min(dist[a][b + 1], x + 1);
            vis[a][b + 1] = true;
            q.push(make_pair(a, b + 1));
        }
    }
}

vector<vector<int>> nearest(vector<vector<int>> &arr, int row, int col)
{
    vector<vector<int>> dist(row, vector<int>(col, 0));
    vector<vector<bool>> vis(row, vector<bool>(col, false));

    bfs(arr, vis, dist, row, col);

    return dist;
}