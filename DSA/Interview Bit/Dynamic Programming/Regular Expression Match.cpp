int Solution::isMatch(const string a, const string b)
{
    int n = a.length(), m = b.length();

    vector<vector<bool>> v(n + 1, vector<bool>(m + 1));

    for (int i = 0; i <= n; i++)
        v[i][0] = false;

    v[0][0] = true;

    for (int i = 1; i <= m; i++)
    {
        v[0][i] = true;
        for (int j = 1; j <= i; j++)
        {
            if (b[j - 1] != '*')
            {
                v[0][i] = false;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1] || b[j - 1] == '?')
                v[i][j] = v[i - 1][j - 1];
            else if (b[j - 1] == '*')
                v[i][j] = v[i - 1][j] || v[i][j - 1];
            else
                v[i][j] = false;
        }
    }
    return v[n][m];
}
