class Solution 
{
    public:
            vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
            {
                vector<int> rest;
                vector<int> ans;
                
                map<int,int> m;
                
                for(int i=0; i<arr2.size(); i++)
                    m[arr2[i]]++;
                
                for(int i=0; i<arr1.size(); i++)
                {
                    if(m[arr1[i]] == 0)
                        rest.push_back(arr1[i]);
                    else
                        m[arr1[i]]++;
                }
                
                for(int i=0; i<arr2.size(); i++)
                {
                    for(int j=0; j<m[arr2[i]]-1; j++)
                        ans.push_back(arr2[i]);
                }
                
                sort(rest.begin(), rest.end());
                
                for(int i=0; i<rest.size(); i++)
                    ans.push_back(rest[i]);
                
                return ans;
            }
};