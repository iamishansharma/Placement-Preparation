#define MXN 38
vector<int> t(MXN);
vector<bool> b(MXN);
class Solution 
{
    public:
            int tribonacci(int n) 
            {
                if(n == 0)
                    return 0;
                
                if(n == 1 || n == 2)
                    return 1;
                
                if(b[n])
                    return t[n];
                else
                {
                    b[n] = true;
                    t[n] = tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
                }
                return t[n];
            }
};