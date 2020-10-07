// { Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

int minStepToReachTarget(int *, int *, int);

// Driver code to test above methods
int main()
{
    // size of square board
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        int a, b, c, d;
        cin >> N;
        cin >> a >> b;
        cin >> c >> d;
        int knightPos[] = {a, b};
        int targetPos[] = {c, d};
        cout << minStepToReachTarget(knightPos, targetPos, N) << endl;
    }
    return 0;
}
// } Driver Code Ends

// User function template for C++

// KnightPos : knight position coordinates
// targetPos : target position coordinated
// N : square matrix size
int minStepToReachTarget(int knightPos[], int targetPos[], int N)
{
    pair<int, int> start = {knightPos[0] - 1, knightPos[1] - 1};
    pair<int, int> target = {targetPos[0] - 1, targetPos[1] - 1};

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<vector<int>> dist(N, vector<int>(N, INT_MAX));

    int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;
    dist[start.first][start.second] = 0;

    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int newx = temp.first + dx[i];
            int newy = temp.second + dy[i];

            if (newx >= 0 && newy >= 0 && newx < N && newy < N && !visited[newx][newy] && dist[newx][newy] > dist[temp.first][temp.second] + 1)
            {
                dist[newx][newy] = dist[temp.first][temp.second] + 1;
                visited[newx][newy] = true;
                q.push({newx, newy});
            }
        }
    }
    return dist[target.first][target.second];
}