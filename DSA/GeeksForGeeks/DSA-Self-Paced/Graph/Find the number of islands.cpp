// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M);

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++)
        {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++)
            {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
} // } Driver Code Ends

/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/
void DFS(int x, int y, vector<int> mat[], int N, int M, vector<vector<bool>> &visited)
{
    if (x < 0 || y < 0 || x >= N || y >= M || visited[x][y] == true || mat[x][y] == 0)
        return;

    visited[x][y] = true;

    int xdir[8] = {0, 0, -1, -1, 1, 1, -1, 1};
    int ydir[8] = {-1, 1, -1, 1, -1, 1, 0, 0};

    for (int i = 0; i < 8; i++)
    {
        int newx = x + xdir[i];
        int newy = y + ydir[i];

        DFS(newx, newy, mat, N, M, visited);
    }
}

void BFS(int x, int y, vector<int> mat[], int N, int M, vector<vector<bool>> &visited)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    int xdir[8] = {0, 0, -1, -1, 1, 1, -1, 1};
    int ydir[8] = {-1, 1, -1, 1, -1, 1, 0, 0};

    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int newx = temp.first + xdir[i];
            int newy = temp.second + ydir[i];

            if (newx < 0 || newy < 0 || newx >= N || newy >= M || visited[newx][newy] == true || mat[newx][newy] == 0)
            {
                continue;
            }
            else
            {
                visited[newx][newy] = true;
                q.push({newx, newy});
            }
        }
    }
}

int findIslands(vector<int> mat[], int N, int M)
{
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    int count = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (mat[i][j] == 1 && !visited[i][j])
            {
                BFS(i, j, mat, N, M, visited);
                count++;
            }
        }
    }

    return count;
}
