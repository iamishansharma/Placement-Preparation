class Solution 
{
    public:
            vector<int> sortedSquares(vector<int>& A) 
            {
                vector<int> ans;
                for(int i=0; i<A.size(); i++)
                {
                    ans.push_back(A[i]*A[i]);
                }
                sort(ans.begin(), ans.end());
                return ans;
            }
};