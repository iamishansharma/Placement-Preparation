// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

void getSum(int currentSum, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans, int index)
{
    if (currentSum == 0)
    {
        ans.push_back(temp);
        return;
    }

    for (int i = index; i < nums.size(); i++)
    {
        if (currentSum - nums[i] >= 0)
        {
            currentSum -= nums[i];

            temp.push_back(nums[i]);

            getSum(currentSum, nums, temp, ans, i);

            // This path got rejected.
            currentSum += nums[i];
            temp.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end()); // Erase Non Unique Elements

    vector<vector<int>> ans;
    vector<int> temp;

    getSum(target, nums, temp, ans, 0);

    return ans;
}

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> A;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            A.push_back(x);
        }
        int sum;
        cin >> sum;
        vector<vector<int>> result;
        result = combinationSum(A, sum);
        if (result.size() == 0)
        {
            cout << "Empty";
        }
        for (int i = 0; i < result.size(); i++)
        {
            cout << '(';
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j];
                if (j < result[i].size() - 1)
                    cout << " ";
            }
            cout << ")";
        }
        cout << "\n";
    }
} // } Driver Code Ends