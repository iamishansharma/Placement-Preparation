// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid.
// Size will be NxN
#define N 9

bool SolveSudoku(int grid[N][N]);

void printGrid(int grid[N][N]);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int grid[N][N];

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                cin >> grid[i][j];

        if (SolveSudoku(grid) == true)
            printGrid(grid);
        else
            cout << "No solution exists";

        cout << endl;
    }

    return 0;
} // } Driver Code Ends

bool isSafe(int i, int j, int num, int grid[N][N])
{
    for (int k = 0; k < N; k++)
        if (grid[i][k] == num || grid[k][j] == num)
            return false;

    int s = sqrt(N);
    int rs = i - i % s;
    int cs = j - j % s;

    for (int i = 0; i < s; i++)
        for (int j = 0; j < s; j++)
            if (grid[i + rs][j + cs] == num)
                return false;

    return true;
}

bool SolveSudoku(int grid[N][N])
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        bool flag = false;

        for (j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
            {
                flag = true;
                break;
            }
        }

        if (flag == true)
            break;
    }

    if (i == N && j == N)
        return true;

    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(i, j, num, grid))
        {
            grid[i][j] = num;

            if (SolveSudoku(grid))
                return true;
            else
                grid[i][j] = 0;
        }
    }

    return false;
}

void printGrid(int grid[N][N])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << " ";
}
