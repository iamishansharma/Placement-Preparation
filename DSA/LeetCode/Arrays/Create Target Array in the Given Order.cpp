class Solution 
{
    public:
            vector<int> createTargetArray(vector<int>& nums, vector<int>& index) 
            {
                vector<int> result;
                result.reserve(nums.size());

                int i = 0;
                
                for(auto & l: index)
                {
                    result.insert(result.begin() + l, nums[i]);
                    i++;
                }
                return result;
            }
};