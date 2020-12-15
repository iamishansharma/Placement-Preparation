// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution
{
public:
    int minimumCost(int cost[], int n, int w)
    {
        vector<int> val;
        vector<int> wt;
        int size = 0;

        for (int i = 0; i < n; i++)
        {
            if (cost[i] != -1)
            {
                val.push_back(cost[i]);
                wt.push_back(i + 1);
                size++;
            }
        }

        n = size;

        vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

        for (int i = 0; i <= w; i++)
            dp[0][i] = INT_MAX / 2;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                if (wt[i - 1] <= j)
                    dp[i][j] = min(dp[i - 1][j], val[i - 1] + dp[i][j - wt[i - 1]]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][w] == (INT_MAX / 2) ? -1 : dp[n][w];
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.minimumCost(a, n, w) << "\n";
    }
    return 0;
} // } Driver Code Ends