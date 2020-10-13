int Solution::solve(int A, vector<vector<int>> &B)
{
    vector<vector<pair<int, int>>> graph(A + 1);

    for (int i = 0; i < B.size(); i++)
    {
        graph[B[i][0]].push_back(make_pair(B[i][1], B[i][2]));
        graph[B[i][1]].push_back(make_pair(B[i][0], B[i][2]));
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int ans = 0;

    vector<bool> vis(A + 1, false);
    vector<int> dis(A + 1, INT_MAX);
    dis[B[0][0]] = 0;
    pq.push(make_pair(0, B[0][0]));

    while (!pq.empty())
    {
        int current_cost = pq.top().first;
        int min_index = pq.top().second;
        pq.pop();

        if (vis[min_index] == false)
        {
            ans += current_cost;
            vis[min_index] = true;
        }

        for (auto i : graph[min_index])
        {
            int v = i.first;
            int cost = i.second;

            if (cost < dis[v] && !vis[v])
            {
                dis[v] = cost;
                pq.push(make_pair(dis[v], v));
            }
        }
    }

    return ans;
}
