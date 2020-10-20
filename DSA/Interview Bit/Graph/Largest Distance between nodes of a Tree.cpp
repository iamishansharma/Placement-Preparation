int dfs(vector<int> adj[], int root, int &ans)
{
    if (adj[root].size() == 0)
        return 1;

    int max1 = 0, max2 = 0;

    for (int i = 0; i < adj[root].size(); i++)
    {
        int h = dfs(adj, adj[root][i], ans);

        if (h > max1)
        {
            max2 = max1;
            max1 = h;
        }
        else if (h > max2)
        {
            max2 = h;
        }
    }

    ans = max(ans, max1 + max2 + 1);
    return max(max1, max2) + 1;
}

int Solution::solve(vector<int> &A)
{
    int n = A.size();
    vector<int> adj[n + 1];
    int root;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == -1)
        {
            root = i;
            continue;
        }
        else
        {
            adj[A[i]].push_back(i);
        }
    }

    int ans = 0;

    if (adj[root].size() == 0)
        return 0;

    dfs(adj, root, ans);

    return ans - 1;
}
