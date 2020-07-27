class Solution 
{
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        vector<bool> ans;
        
        int maxval = INT_MIN;
        
        for(int i=0; i<candies.size(); i++)
            maxval = max(maxval, candies[i]);
        
        for(int i=0; i<candies.size(); i++)
            if(candies[i] + extraCandies >= maxval)
                ans.push_back(true);
            else
                ans.push_back(false);
        
        return ans;
    }
};