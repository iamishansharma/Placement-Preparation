class Solution 
{
    public:
        int findLengthOfLCIS(vector<int>& nums) 
        {
            if(nums.size() == 0)
                return 0;
            
            int current = 1;
            int maxval = 1;
            
            for(int i=1; i<nums.size(); i++)
            {
                if(nums[i] > nums[i-1])
                    current++;
                else
                    current = 1;
                maxval = max(maxval, current);
            }
            
            return maxval;
        }
};