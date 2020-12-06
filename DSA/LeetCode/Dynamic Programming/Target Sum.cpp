class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int k)
    {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];

        if (sum < k)
            return 0;

        if ((sum + k) % 2 != 0)
            return 0;

        int S = (sum + k) / 2;

        int t[n + 1][S + 1];
        int zero = 0;

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < S + 1; j++)
            {
                if (i == 0 && j == 0)
                    t[i][j] = 1;

                else if (i == 0)
                    t[i][j] = 0;

                else if (j == 0)
                {
                    if (nums[i - 1] == 0)
                        zero++;
                    t[i][j] = pow(2, zero);
                }
                else if (nums[i - 1] <= j)
                    t[i][j] = t[i - 1][j] + t[i - 1][j - nums[i - 1]];
                else
                    t[i][j] = t[i - 1][j];
            }
        }
        return t[n][S];
    }
};