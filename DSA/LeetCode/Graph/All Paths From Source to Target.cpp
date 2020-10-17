class Solution
{
public:
    void DFS(int start, vector<vector<int>> &graph, vector<int> path, vector<vector<int>> &ans)
    {
        path.push_back(start);

        if (start == graph.size() - 1)
            ans.push_back(path);

        for (int i = 0; i < graph[start].size(); i++)
            DFS(graph[start][i], graph, path, ans);
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> ans;

        for (int i = 0; i < graph[0].size(); i++)
        {
            vector<int> path;
            path.push_back(0);
            DFS(graph[0][i], graph, path, ans);
        }

        return ans;
    }
};