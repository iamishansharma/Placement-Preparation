int Solution::solve(string A, string B, vector<string> &C)
{
    unordered_map<string, bool> vis;

    for (string temp : C)
        vis[temp] = false;

    if (vis.find(B) == vis.end())
        return 0;

    queue<string> q;
    q.push(A);
    vis[A] = true;

    int level = 1;

    while (!q.empty())
    {
        int qsize = q.size();

        while (qsize--)
        {
            string s = q.front();
            q.pop();

            for (int i = 0; i < s.size(); i++)
            {
                string temp = s;

                for (int j = 0; j < 26; j++)
                {
                    temp[i] = j + 'a';

                    if (temp == B)
                        return level + 1;

                    if (vis.find(temp) != vis.end() and vis[temp] == false)
                    {
                        vis[temp] = true;
                        q.push(temp);
                    }
                }
            }
        }
        level++;
    }
    return level;
}
