class Solution 
{
    public:
            static bool comp(pair<int,int> a, pair<int,int> b)
            {
                return a.first == b.first ? a.second < b.second : a.first < b.first;
            }
            vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
            {
                vector<pair<int,int>> weak;
                
                for(int i=0; i<mat.size(); i++)
                {
                    int count = 0;
                    for(int j=0; j<mat[i].size(); j++)
                        if(mat[i][j] == 1)
                            count++;
                    weak.push_back({count, i});
                }
                
                sort(weak.begin(), weak.end(), comp);
                
                vector<int> ans;
                
                for(int i=0; i<k; i++)
                    ans.push_back(weak[i].second);
                
                return ans;
            }
};