int Solution::knight(int N, int M, int startx, int starty, int destx, int desty)
{
    vector<vector<int>> distance(N, vector<int>(M, INT_MAX));
    distance[startx - 1][starty - 1] = 0; // 1 indexing

    int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

    queue<pair<int, int>> q;
    q.push({startx - 1, starty - 1});

    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int newx = temp.first + dx[i];
            int newy = temp.second + dy[i];

            if (newx >= 0 && newy >= 0 && newx < N && newy < M && distance[newx][newy] > distance[temp.first][temp.second] + 1)
            {
                distance[newx][newy] = distance[temp.first][temp.second] + 1;
                q.push({newx, newy});
            }
        }
    }

    return distance[destx - 1][desty - 1] == INT_MAX ? -1 : distance[destx - 1][desty - 1];
}
