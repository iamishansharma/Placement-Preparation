class Solution 
{
    public:
            int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) 
            {
                set<pair<int,int>> obs;
                
                for(int i=0; i<obstacles.size(); i++)
                    obs.insert({obstacles[i][0] , obstacles[i][1]});

                vector<int> pos = {0,0};
                int d = 0;
                vector<vector<int>> di = {{0,1},{1,0},{0,-1},{-1,0}};
                int ans = 0;

                for(int i=0; i<commands.size(); i++)
                {
                    if(commands[i] == -2)
                        d = (d + 4 - 1) % 4;
                    else if(commands[i]==-1)
                        d = (d + 1) % 4;
                    else if(commands[i] > 0)
                    {
                        for(int j=0; j < commands[i]; j++)
                        {
                            if(obs.find({pos[0] + di[d][0], pos[1] + di[d][1]}) == obs.end())
                            {
                                pos[0] += di[d][0];
                                pos[1] += di[d][1];
                            }
                            else  
                                break;
                        }
                        ans = max(ans, pos[0]*pos[0] + pos[1]*pos[1]);
                    }
                }

                return  ans;
            }
};