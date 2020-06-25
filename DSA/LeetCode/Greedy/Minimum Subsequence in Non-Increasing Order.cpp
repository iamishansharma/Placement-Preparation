//https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/

class Solution 
{
public:
    vector<int> minSubsequence(vector<int>& nums) 
    {
        int sum=0, newsum=0;
        
        vector<int>ans;
        
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        
        sort(nums.begin(),nums.end(),std::greater<>());
        
        for(int i=0; i<nums.size(); i++)
        {
            newsum += nums[i];
            sum = sum - nums[i];
            ans.push_back(nums[i]);
            
            if(newsum > sum)
                break;
        }
        
        sort(ans.begin(),ans.end(),std::greater<>());
        
        return ans;
    }
};