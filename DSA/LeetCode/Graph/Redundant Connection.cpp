class Solution
{
public:
    /*
     * Find the subset a vertex belongs to.
     */
    int find(vector<int> &ss, int x)
    {
        if (ss[x] == -1)
            return x;
        return find(ss, ss[x]);
    }

    void _union(vector<int> &ss, int x, int y)
    {
        int xp = find(ss, x);
        int yp = find(ss, y);

        if (xp != yp)
            ss[yp] = xp;
    }

    vector<int> findRedundantConnection(vector<vector<int>> &e /*dges*/)
    {
        vector<int> ss;
        ss.push_back(-1);

        for (int i = 0; i < e.size(); i++)
            ss.push_back(-1);

        for (int i = 0; i < e.size(); ++i)
        {
            int x = find(ss, e[i][0]);
            int y = find(ss, e[i][1]);

            if (x == y)
                return {e[i][0], e[i][1]};

            _union(ss, x, y);
        }

        /* No redundant edge found */
        return vector<int>();
    }
};