class Solution
{
public:
    bool Recursion(vector<int> &nums, int k, vector<bool> &visited, int targetSum, int currentSum, int currentIndex)
    {
        if (k == 0)
            return true;

        if (currentSum == targetSum)
            return Recursion(nums, k - 1, visited, targetSum, 0, 0);

        for (int i = currentIndex; i < nums.size(); i++)
        {
            if (!visited[i] && currentSum + nums[i] <= targetSum)
            {
                visited[i] = true;

                if (Recursion(nums, k, visited, targetSum, currentSum + nums[i], i + 1))
                    return true;

                visited[i] = false;
            }
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sum = 0;

        int n = nums.size();

        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++)
            sum += nums[i];

        if (sum % k != 0)
            return false;
        else
            return Recursion(nums, k, visited, sum / k, 0, 0);
    }
};