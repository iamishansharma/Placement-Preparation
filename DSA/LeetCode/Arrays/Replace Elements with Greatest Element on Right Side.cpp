class Solution 
{
    public:
            vector<int> replaceElements(vector<int>& arr) 
            {
                int maxval = INT_MIN;
                
                int n = arr.size();
                int temp = 0;
                
                for(int i=n-1; i>=0; i--)
                {
                    if(i == n-1)
                    {
                        maxval = arr[i];
                        arr[i] = -1;
                    }
                    else
                    {
                        temp = arr[i];
                        arr[i] = maxval;
                        maxval = max(maxval, temp);
                    }
                }
                
                return arr;
            }
};