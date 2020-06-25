//https://leetcode.com/problems/lemonade-change/

class Solution 
{
    public:
            bool lemonadeChange(vector<int>& bills) 
            {
                int change5 = 0;
                int change10 = 0;
                
                bool ans = true;
                
                for(int i=0; i<bills.size(); i++)
                {
                    if(bills[i] == 5)
                        change5++;
                    else if(bills[i] == 10)
                    {
                        if(change5 == 0)
                        {
                            ans = false;
                            break;
                        }
                        else
                        {
                            change5--;
                            change10++;
                        }
                    }
                    else
                    {
                        if(change10 >= 1 && change5 >=1)
                        {
                            change10--;
                            change5--;
                        }
                        else if(change5 >= 3)
                        {
                            change5 -= 3;
                        }
                        else
                        {
                            ans = false;
                            break;
                        }
                    }
                }
                
                return ans;
            }
};