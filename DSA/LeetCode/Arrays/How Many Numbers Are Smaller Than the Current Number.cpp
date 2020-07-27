class Solution 
{
    public:
            vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
            {
                vector<int> res;
                
                int count_arr[101] = {0}; // Since nums[i] can have max value of 100
                int count_array_size = 0;
                int i = 0, val = 0;

                for (i = 0; i < nums.size(); i++)
                {
                    count_arr[nums[i]]++;
                    
                    if (nums[i] > count_array_size) // Getting the max range
                        count_array_size = nums[i];
                }

                int count_sum_arr[101] = {0};
                count_sum_arr[0] = 0;
                
                for (i = 1; i <= count_array_size; i++)
                    count_sum_arr[i] = count_sum_arr[i - 1] + count_arr[i-1];

                for (i = 0; i < nums.size(); i++)
                {
                    val = count_sum_arr[nums[i]];
                    res.push_back(val);
                }

                return res;
            }
};