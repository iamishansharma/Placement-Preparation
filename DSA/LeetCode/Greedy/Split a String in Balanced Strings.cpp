//https://leetcode.com/problems/split-a-string-in-balanced-strings/

class Solution 
{
    public:
            int balancedStringSplit(string s) 
            {
                int count = 0;
                
                int match = 0;
                
                for(auto i:s)
                {
                    if(i == 'L')
                        match++;
                    else
                        match--;
                    
                    if(match == 0)
                        count++;
                }
                
                return count;
            }
};