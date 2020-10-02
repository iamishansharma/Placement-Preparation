// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

#define SIZE 100

// } Driver Code Ends

/*  Function to find the area of 1s
*   SIZE: declared globally for matrix definition
*   n, m: row and column of matrix
*   A[][]: 2D matrix from input
*/
void DFS(int i, int j, int A[SIZE][SIZE], int &area, int n, int m)
{
    if (i >= 0 && i < n && j >= 0 && j < m && A[i][j] == 1)
    {
        area += 1;
        A[i][j] = -1; // Works as visited

        int row[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int col[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int k = 0; k < 8; k++)
        {
            int newx = i + row[k];
            int newy = j + col[k];

            DFS(newx, newy, A, area, n, m);
        }
    }
    else
        return;
}

int findMaxArea(int n, int m, int A[SIZE][SIZE])
{
    int maxval = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] == 1)
            {
                int area = 0;
                DFS(i, j, A, area, n, m);
                maxval = max(maxval, area);
            }
        }
    }

    return maxval;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int g[SIZE][SIZE];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> g[i][j];

        cout << findMaxArea(n, m, g) << endl;
    }

    return 0;
} // } Driver Code Ends