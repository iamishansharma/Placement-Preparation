/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> m;
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node)
{
    if (!node)
        return NULL;

    UndirectedGraphNode *root = new UndirectedGraphNode(node->label);
    m[node] = root;

    for (auto n : node->neighbors)
    {
        if (m.find(n) == m.end())
        {
            UndirectedGraphNode *nei = cloneGraph(n);
            root->neighbors.push_back(nei);
        }
        else
            root->neighbors.push_back(m[n]);
    }
    return root;
}
