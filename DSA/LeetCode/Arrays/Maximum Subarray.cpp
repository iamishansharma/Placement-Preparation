class Solution 
{
    public:
            int maxSubArray(vector<int>& nums) 
            {
                int cur_max = nums[0];
                int max_so_far = nums[0];
                
                for(int i=1; i<nums.size(); i++)
                {
                    cur_max = max(nums[i], cur_max + nums[i]);
                    max_so_far = max(cur_max,max_so_far);
                }
                return max_so_far;
            }
};