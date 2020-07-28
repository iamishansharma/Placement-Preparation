class Solution 
{
    private:
            int mn=0, sum=0;
    public:
            int minStartValue(vector<int>& nums) 
            {
                for(int i:nums) 
                    sum+=i, mn=min(mn,sum);
                return abs(mn)+1;
            }
};