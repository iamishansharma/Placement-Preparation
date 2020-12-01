vector<int> helper(int start, int end, vector<int> &B, long long &cost, map<pair<int, int>, pair<long long, vector<int>>> &dp)
{
    vector<int> ans;
    int m = B.size();
    if (dp.find({start, end}) != dp.end())
    {
        pair<long long, vector<int>> pi = dp[{start, end}];
        cost = pi.first;
        return pi.second;
    }
    if (B.size() == 1)
    {
        if (B[0] < start || end < B[0])
        {
            cost = 0.0;
        }
        else
        {
            ans.push_back(B[0]);
            cost = end - start;
        }
        return ans;
    }
    long long l, r;
    long long ans1 = INT_MAX;
    cost = LONG_MAX;
    vector<int> lans, rans;
    for (int i = 0; i < m; i++)
    {
        vector<int> larr, rarr;
        if (B[i] < start || end < B[i])
            continue;
        int temp = B[i];
        B[i] = INT_MIN;
        rarr = helper(temp, end, B, r, dp);
        larr = helper(start, temp, B, l, dp);

        B[i] = temp;
        if (cost > l + r)
        {
            cost = l + r;
            ans1 = temp;
            ans.clear();
            lans = larr;
            rans = rarr;
        }
    }
    for (int i : rans)
        ans.push_back(i);
    for (int i : lans)
        ans.push_back(i);

    if (ans1 != INT_MAX)
        ans.push_back(ans1);
    cost = cost == LONG_MAX ? 0 : cost + (end - start);
    dp[{start, end}] = {cost, ans};
    return ans;
}

vector<int> Solution::rodCut(int A, vector<int> &B)
{
    long long cost = 0;
    sort(B.begin(), B.end());
    map<pair<int, int>, pair<long long, vector<int>>> dp;
    vector<int> ans = helper(0, A, B, cost, dp);
    reverse(ans.begin(), ans.end());
    return ans;
}