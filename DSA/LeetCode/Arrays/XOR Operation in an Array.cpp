class Solution 
{
    public:
            int xorOperation(int n, int start) 
            {
                int i = 0;
                int j = 0;
                
                while( i < n)
                {
                    j ^= start+ 2*i;
                    i++;
                }
                return j;
            }
};