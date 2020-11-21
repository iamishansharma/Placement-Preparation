// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int nthStair(int n)
    {
        vector<int> dp(n + 1, 0);

        dp[0] = 1;

        for (int i = 1; i <= n; i++)
            dp[i] += dp[i - 1];

        for (int j = 2; j <= n; j++)
            dp[j] += dp[j - 2];

        return dp[n];
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.nthStair(n);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends