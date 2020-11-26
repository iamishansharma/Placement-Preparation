// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int DivisibleByM(vector<int> nums, int m)
    {
        int n = nums.size();

        if (n > m)
            return true;

        int dp[1001][1001];

        memset(dp, -1, sizeof(dp));

        return divisibleUtil(nums, n, m, 0, dp);
    }

    int divisibleUtil(vector<int> &nums, int n, int m, int modulo, int dp[1001][1001])
    {
        if (n == 0)
            return false;

        if (nums[n - 1] % m == modulo)
            return true;

        if (dp[n][modulo] != -1)
            return dp[n][modulo];

        int nextModulo = modulo - (nums[n - 1] % m);

        if (nextModulo < 0)
            nextModulo += m;

        int include = divisibleUtil(nums, n - 1, m, nextModulo, dp);
        int exclude = divisibleUtil(nums, n - 1, m, modulo, dp);

        dp[n][modulo] = include || exclude;

        return dp[n][modulo];
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.DivisibleByM(nums, m);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends