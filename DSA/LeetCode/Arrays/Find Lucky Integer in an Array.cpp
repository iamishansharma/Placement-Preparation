class Solution 
{
    public:
            int findLucky(vector<int>& arr) 
            {
                int com[501] = {0}
                ;
                for(int i=0;i<arr.size();i++)
                    com[arr[i]]++;
                
                for(int i=500; i>0; i--)
                    if(com[i] == i)
                        return i;
                
                return -1;
            }
};