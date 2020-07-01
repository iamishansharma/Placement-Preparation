//https://leetcode.com/problems/partition-labels/submissions/

class Solution 
{
    public:
            vector<int> partitionLabels(string S) 
            {
                vector<int> hash(26, -1), res;
                
                int i, start, end;
                
                for(i = 0; i < S.size(); i++)
                    hash[S[i]-'a'] = i;
                
                start = i = 0;
                
                while(i < S.size())
                {
                    end = hash[S[i]-'a'];
                    
                    while(i < end)
                    {
                        if(hash[S[i]-'a'] > end)
                            end = hash[S[i]-'a'];
                        
                        i++;
                    }
                    
                    res.push_back(end - start + 1);
                    
                    i++;
                    start = i;
                }
                return res;
            }
};