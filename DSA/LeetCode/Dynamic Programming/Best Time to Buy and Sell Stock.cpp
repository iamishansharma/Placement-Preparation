class Solution 
{
    public:
            int maxProfit(vector<int>& prices) 
            {
                if(prices.empty())
                    return 0;
                
                int ans = 0;
                
                int minval = INT_MAX;
                
                int n = prices.size();
                
                vector<int> mtn(n);
                
                mtn[0] = prices[0];
                minval = mtn[0];
                
                for(int i=1; i<n; i++)
                {
                    minval = min(minval, prices[i]);
                    mtn[i] = minval;
                }
                
                for(int i=0; i<n; i++)
                    mtn[i] = prices[i] - mtn[i];
                
                for(int i=0; i<n; i++)
                    ans = max(ans, mtn[i]);
                
                return ans;
            }
};