
bool isSafe(vector<int> &x_cor, vector<int> &y_cor, int &r, int x, int y, int &m, int &n, vector<vector<bool>> &vis)
{
    if (x < 0 || x > m || y < 0 || y > n)
        return false;
    if (vis[x][y] == true)
        return false;
    for (int i = 0; i < x_cor.size(); i++)
    {
        int dis = (pow(x - x_cor[i], 2) + pow(y - y_cor[i], 2));
        if (dis <= r * r)
            return false;
    }
    return true;
}

int x_dir[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y_dir[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool dfs(vector<int> &x_cor, vector<int> &y_cor, int &r, int x, int y, int m, int n, vector<vector<bool>> &vis)
{
    if (x == m && y == n)
        return true;
    vis[x][y] = true;

    for (int i = 0; i < 8; i++)
    {
        int x1 = x + x_dir[i];
        int y1 = y + y_dir[i];
        if (isSafe(x_cor, y_cor, r, x1, y1, m, n, vis))
        {
            if (dfs(x_cor, y_cor, r, x1, y1, m, n, vis))
                return true;
        }
    }
    return false;
}

#define x A
#define y B
#define n C
#define r D
#define x_cor E
#define y_cor F

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F)
{

    vector<vector<bool>> vis(x + 1, vector<bool>(y + 1, false));

    if (dfs(x_cor, y_cor, r, 0, 0, x, y, vis))
        return "YES";
    else
        return "NO";
}