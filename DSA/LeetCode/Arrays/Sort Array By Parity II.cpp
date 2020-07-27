class Solution 
{
    public:
            vector<int> sortArrayByParityII(vector<int>& A) 
            {
                vector<int> ans(A.size());
                int evenIndex = 0;
                int oddIndex = 1;
                
                for(int i=0; i<A.size(); i++)
                {
                    if(A[i] % 2 == 0)
                    {
                        ans[evenIndex] = A[i];
                        evenIndex += 2;
                    }
                    else
                    {
                        ans[oddIndex] = A[i];
                        oddIndex += 2;
                    }
                    
                }
                return ans;
            }
};