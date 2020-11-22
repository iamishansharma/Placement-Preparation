// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int wildCard(string pattern, string str);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        cout << wildCard(pat, text) << endl;
    }
}
// } Driver Code Ends

/*You are required to complete this method*/
int wildCard(string pattern, string str)
{
    int m = pattern.size();
    int n = str.size();

    bool dp[n + 1][m + 1];

    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < m + 1; j++)
            dp[i][j] = false;

    dp[0][0] = true; //if both string and pattern are empty

    // kind of base case

    for (int i = 1; i <= m; i++)
        if (pattern[i - 1] == '*') //if pattern starts with '*'
            dp[0][i] = dp[0][i - 1];

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (pattern[j - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        }
    }

    return dp[n][m];
}