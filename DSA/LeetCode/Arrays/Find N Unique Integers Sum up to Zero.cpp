class Solution 
{
    public:
            vector<int> sumZero(int n) 
            {
                int i = 0;
                int j = n;
                
                vector<int>v;
                
                if(n % 2 != 0)
                {
                    v.push_back(0);
                    i++;
                }
                for(; i<n; i = i+2)
                {
                    v.push_back(-j);
                    v.push_back(j);
                    j--;
                }
                return v;
            }
};