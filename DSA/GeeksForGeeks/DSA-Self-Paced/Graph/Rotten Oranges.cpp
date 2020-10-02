// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function template for C++

// matrix : given matrix
// R and C : number of rows and columns respectively

bool isSafe(vector<vector<int>> &mat, int n, int m, int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m && mat[i][j] == 1);
}

int rotOranges(vector<vector<int>> &mat, int n, int m)
{
    int timer = -1;
    int countFresh = 0;

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 2)
            {
                q.push({i, j});
                mat[i][j] = 3;
            }
            else if (mat[i][j] == 1)
                countFresh++;
        }
    }

    while (q.empty() == false)
    {
        int count = q.size();

        for (int k = 0; k < count; k++)
        {
            auto index = q.front();
            q.pop();
            int i = index.first;
            int j = index.second;

            if (isSafe(mat, n, m, i, j + 1) == true)
            {
                q.push({i, j + 1});
                mat[i][j + 1] = 3;
                countFresh--;
            }

            if (isSafe(mat, n, m, i + 1, j) == true)
            {
                q.push({i + 1, j});
                mat[i + 1][j] = 3;
                countFresh--;
            }

            if (isSafe(mat, n, m, i, j - 1) == true)
            {
                q.push({i, j - 1});
                mat[i][j - 1] = 3;
                countFresh--;
            }

            if (isSafe(mat, n, m, i - 1, j) == true)
            {
                q.push({i - 1, j});
                mat[i - 1][j] = 3;
                countFresh--;
            }
        }

        timer++;
    }

    return countFresh == 0 ? timer : -1;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> matrix(R);
        for (int i = 0; i < R; ++i)
        {
            matrix[i].resize(C);
            for (int j = 0; j < C; ++j)
                cin >> matrix[i][j];
        }
        cout << rotOranges(matrix, R, C) << endl;
    }
    return 0;
} // } Driver Code Ends