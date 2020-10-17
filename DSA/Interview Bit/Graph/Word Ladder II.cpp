vector<vector<string>> Solution::findLadders(string start, string end, vector<string> &d)
{
    queue<vector<string>> paths;
    vector<vector<string>> ans;
    paths.push({start});

    if (start == end)
    {
        ans.push_back({start});
        return ans;
    }

    unordered_set<string> dict;

    for (int i = 0; i < d.size(); i++)
    {
        dict.insert(d[i]);
    }

    int level = 1;
    int min_level = INT_MAX;

    unordered_set<string> visited;

    while (!paths.empty())
    {
        vector<string> path = paths.front();
        paths.pop();

        if (path.size() > level)
        {
            for (auto w : visited)
            {
                dict.erase(w);
            }
            visited.clear();
            if (path.size() > min_level)
                break;
            else
                level = path.size();
        }
        string last = path.back();

        for (int i = 0; i < last.length(); i++)
        {
            string news = last;
            for (int j = 'a'; j <= 'z'; j++)
            {
                news[i] = j;
                if (dict.find(news) != dict.end())
                {
                    vector<string> newpath = path;
                    newpath.push_back(news);
                    visited.insert(news);

                    if (news == end)
                    {
                        min_level = level;
                        ans.push_back(newpath);
                    }
                    else
                    {
                        paths.push(newpath);
                    }
                }
            }
        }
    }
    return ans;
}
