int Solution::fibsum(int A)
{
    vector<int> dp(50, 1);
    int i = 2;
    while (dp[i - 1] < A)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
        i++;
    }
    queue<pair<int, int>> q;
    q.push(make_pair(A, 0));
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        int x = p.first;
        int level = p.second;
        if (x == 0)
            return level;
        q.pop();
        for (int k = i - 1; k >= 1; k--)
        {
            if (x - dp[k] >= 0)
            {
                q.push(make_pair(x - dp[k], level + 1));
                break;
            }
        }
    }
    return -1;
}
