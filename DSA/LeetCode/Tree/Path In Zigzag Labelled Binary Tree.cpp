class Solution 
{
    public:
            vector<int> pathInZigZagTree(int label)
            {
                double lvl = floor(log2(label)) + 1;
                vector<int> res;
                res.push_back(label);
                for(int i=lvl ; lvl>=2 ; lvl--)
                {
                    int val=pow(2,lvl-1) + pow(2, lvl)-1-label;
                    label=val/2;
                    res.push_back(label);
                }
                reverse(res.begin(), res.end());
                return res;
            }
};