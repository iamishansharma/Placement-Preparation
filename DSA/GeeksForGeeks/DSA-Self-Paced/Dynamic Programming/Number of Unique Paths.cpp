// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int NumberOfPath(int, int);

// Position this line where user code will be pasted

int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //taking dimensions of the matrix
        int a, b;
        cin >> a >> b;

        //calling NumberOfPath() function
        cout << NumberOfPath(a, b) << endl;
    }
}

// } Driver Code Ends

//User function template in C++

int NumberOfPath(int n, int m)
{
    int mat[n][m];

    mat[0][0] = 1;

    for (int i = 0; i < n; i++)
        mat[i][0] = 1;
    for (int j = 0; j < m; j++)
        mat[0][j] = 1;

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            mat[i][j] = mat[i - 1][j] + mat[i][j - 1];

    return mat[n - 1][m - 1];
}
