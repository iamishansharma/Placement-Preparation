//https://leetcode.com/problems/two-city-scheduling/submissions/

class Solution 
{
    public:
            static bool cmp(vector<int> a, vector<int> b)
            {
                if(a[1]-a[0] == b[1]-b[0])
                    return a[0] < b[0];
                else
                    return a[1] - a[0] < b[1] - b[0];
            }
    
            int twoCitySchedCost(vector<vector<int>>& costs) 
            {
                sort(costs.begin(), costs.end(), cmp);
                
                for(int i=0; i<costs.size(); i++)
                {
                    cout<<costs[i][0]<<" "<<costs[i][1]<<endl;
                }
                
                int ans = 0;
                
                for(int i=0; i<costs.size(); i++)
                {
                    if(i < costs.size()/2)
                        ans += costs[i][1];
                    else
                        ans += costs[i][0];
                }
                
                return ans;
            }
};