class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int V = rooms.size();
        vector<bool> visited(V, false);

        queue<int> q;
        q.push(0);
        visited[0] = true;

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (int i = 0; i < rooms[front].size(); i++)
            {
                if (!visited[rooms[front][i]])
                {
                    visited[rooms[front][i]] = true;
                    q.push(rooms[front][i]);
                }
            }
        }

        for (int i = 0; i < visited.size(); i++)
            if (!visited[i])
                return false;

        return true;
    }
};