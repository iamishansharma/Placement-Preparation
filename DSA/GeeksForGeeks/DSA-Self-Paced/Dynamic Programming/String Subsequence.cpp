// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution
{
public:
    int countWays(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = dp[i - 1][j];

                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] += dp[i - 1][j - 1];
            }
        }

        return dp[n][m];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S1, S2;
        cin >> S1;
        cin >> S2;

        Solution ob;
        cout << ob.countWays(S1, S2) << endl;
    }
    return 0;
} // } Driver Code Ends