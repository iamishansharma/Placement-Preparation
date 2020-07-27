class Solution 
{
    public:
            vector<int> sortArrayByParity(vector<int>& A) 
            {
                vector<int> ans(A.size());
                int up=0;
                int down=A.size()-1;
                
                for(int i=0; i<A.size(); i++)
                {
                    if(A[i] % 2 == 0)
                        ans[up++] = A[i];
                    else
                        ans[down--] = A[i];
                }
                
                return ans;
            }
};