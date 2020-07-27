class Solution 
{
    public:
            int countNegatives(vector<vector<int>>& arr) 
            {
                int k=0;
                
                int i=0,j=arr[0].size()-1;
                
                while(i<arr.size() && j>=0)
                {
                    if(arr[i][j]<0)
                    {
                        k += (arr.size()-i);
                        j--;
                    }
                    else if(arr[i][j]>=0)
                        i++;
                }

                return k;
            }
};