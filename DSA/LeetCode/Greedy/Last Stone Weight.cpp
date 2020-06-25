//https://leetcode.com/problems/last-stone-weight/

class Solution 
{
    public:
            int lastStoneWeight(vector<int>& stones) 
            {
                priority_queue<int> pq(stones.begin(), stones.end());
                
                while(pq.size() > 1)
                {
                    int n1 = pq.top();
                    pq.pop();
                    int n2 = pq.top();
                    pq.pop();
                    
                    if(n1 != n2)
                        pq.push(n1-n2);
                }
                
                return pq.empty() ? 0 : pq.top();
            }
};