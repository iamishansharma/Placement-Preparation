class Solution 
{
    public:
            int minTimeToVisitAllPoints(vector<vector<int>>& points) 
            {
                int res=0;
                
                for(int i=0; i < points.size()-1; i++)
                {
                    int hor = abs(points[i+1][0] - points[i][0]);
                    int vert = abs(points[i+1][1] - points[i][1]);
                    res += max(hor,vert);
                }
                return res;
            }
};