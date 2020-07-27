class Solution 
{
    public:
            int numIdenticalPairs(vector<int>& nums) 
            {
                vector<int> v(101, 0);
                
                int sum = 0;
                
                for(int i: nums)
                    v[i]++;
                
                for(int i: v)
                    sum += i*(i-1)/2;
                
                return sum;
            }
};