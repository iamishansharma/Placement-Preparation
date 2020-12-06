int Solution::bulbs(vector<int> &A)
{
    int ans = 0, i;
    int n = A.size();

    if (A.size() != 0)
    {
        if (A[i] == 0)
            ans = 1;

        for (i = 1; i < n; i++)
        {
            if (A[i] != A[i - 1])
                ans++;
        }
    }
    return ans;
}
