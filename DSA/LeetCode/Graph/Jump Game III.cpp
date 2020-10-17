class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        /*vector<bool> visited(arr.size(), false);
                
                queue<int> q;
                q.push(start);
                visited[start] = true;
                
                while(!q.empty())
                {
                    int front = q.front();
                    q.pop();
                    
                    if(arr[front] == 0)
                        return true;
                
                    if(front + arr[front] >= 0 && front + arr[front] < arr.size())
                    {
                        if(!visited[front + arr[front]])
                        {
                            visited[front + arr[front]] = true;
                            q.push(front + arr[front]);
                        }
                    }
                    
                    if(front - arr[front] >= 0 && front - arr[front] < arr.size())
                    {
                        if(!visited[front - arr[front]])
                        {
                            visited[front - arr[front]] = true;
                            q.push(front - arr[front]);
                        }
                    }
                }
                
                return false;*/

        if (start < 0 || start >= arr.size() || arr[start] < 0)
            return false;

        if (arr[start] == 0)
            return true;

        arr[start] = -arr[start];

        return canReach(arr, start + arr[start]) || canReach(arr, start - arr[start]);
    }
};