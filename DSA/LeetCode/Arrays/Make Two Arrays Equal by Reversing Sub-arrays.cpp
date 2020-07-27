class Solution 
{
    public:
            bool canBeEqual(vector<int>& target, vector<int>& arr) 
            {
                if(arr == target)
                    return true;
                
                unordered_map<int,int> m1;
                unordered_map<int,int> m2;
                
                int n = target.size();
                
                for(int i=0; i<n; i++)
                {
                    m1[target[i]]++;
                    m2[arr[i]]++;
                }
                
                if(m1 == m2)
                    return true;
                else
                    return false;
            }
};