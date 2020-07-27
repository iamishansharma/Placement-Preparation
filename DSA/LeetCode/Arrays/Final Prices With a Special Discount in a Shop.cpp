class Solution 
{
    public:
            vector<int> finalPrices(vector<int>& prices) 
            {
                int i=0, n=prices.size();
                
                stack<int> st={};
                vector<int> ans(n);
                
                while(i<n)
                {
                    while(!st.empty() && prices[i]<=prices[st.top()])
                    {
                        ans[st.top()]=prices[st.top()]-prices[i];
                        st.pop();
                    }
                    st.push(i++);
                }
                while(!st.empty())
                {
                    ans[st.top()]=prices[st.top()];
                    st.pop();
                }
                return ans;
            }
};