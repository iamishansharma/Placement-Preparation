class Solution 
{
    public:
            double average(vector<int>& salary) 
            {
                int minval = INT_MAX;
                int maxval = INT_MIN;
                
                for(int i=0; i<salary.size(); i++)
                {
                    minval = min(minval, salary[i]);
                    maxval = max(maxval, salary[i]);
                }
                double sum = 0;
                for(int i=0; i<salary.size(); i++)
                {
                    if(salary[i] != minval && salary[i] != maxval)
                        sum += salary[i];
                } 
                return sum/(salary.size()-2);
            }
};