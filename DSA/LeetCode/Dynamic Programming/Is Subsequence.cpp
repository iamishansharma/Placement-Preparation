class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        //         int n = t.size();
        //         int m = s.size();

        //         vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        //         for(int i=1; i<=n; i++)
        //         {
        //             for(int j=1; j<=m; j++)
        //             {
        //                 if(t[i-1] == s[j-1])
        //                     dp[i][j] = dp[i-1][j-1] + 1;
        //                 else
        //                     dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        //             }
        //         }

        //         // for(int i=0; i<=n; i++)
        //         // {
        //         //     for(int j=0; j<=m; j++)
        //         //     {
        //         //         cout<<dp[i][j]<<" ";
        //         //     }
        //         //     cout<<endl;
        //         // }

        //         return m == dp[n][m];

        int n = t.size();
        int m = s.size();

        int i = 0;
        int j = 0;

        while (i < n)
        {
            //cout<<t[i]<<" "<<s[j]<<endl;

            if (t[i] == s[j])
                j++;

            i++;
        }

        return j == m;
    }
};