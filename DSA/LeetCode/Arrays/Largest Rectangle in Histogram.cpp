class Solution 
{
    public:
            int largestRectangleArea(vector<int>& height) 
            {
                int ret = 0;
                height.push_back(0);
                stack<int> index;

                for(int i = 0; i < height.size(); i++)
                {
                    while(index.size() > 0 && height[index.top()] >= height[i])
                    {
                        int h = height[index.top()];
                        index.pop();

                        int sidx = index.size() > 0 ? index.top() : -1;
                        
                        ret = max(ret, h * (i-sidx-1));
                    }
                    index.push(i);
                }
                return ret;
            }
};