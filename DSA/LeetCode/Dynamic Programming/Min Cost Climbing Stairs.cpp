class Solution 
{
    public:
            int minCostClimbingStairs(vector<int>& c) 
            {
                int dp[c.size()+1];
                
                c.push_back(0);
                
                dp[0] = c[0];
                
                for(int i=1; i<c.size(); i++)
                {
                    int val=0;
                    
                    if(i-2 >= 0) 
                        val = dp[i-2];
                    
                    dp[i] = min(c[i]+dp[i-1],val+c[i]);
                }
                return dp[c.size()-1];
            }
};