class Solution 
{
    public:
            int trap(vector<int>& height) 
            {
                int n = height.size();
                
                if(n == 0)
                    return 0;
                
                vector<int> left(n);
                vector<int> right(n);
                
                left[0] = height[0];
                right[n-1] = height[n-1];
                
                for(int i=1; i<n; i++)
                {
                    left[i] = max(height[i], left[i-1]);
                    right[n-1 - i] = max(right[n-1 - i + 1], height[n-1-i]);
                }
                
                int water = 0;
                
                for(int i=0; i<n; i++)
                    water += (min(left[i], right[i]) - height[i]);
                
                return water;
            }
};