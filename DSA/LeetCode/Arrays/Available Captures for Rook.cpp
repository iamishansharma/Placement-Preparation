class Solution 
{
    public:
            int numRookCaptures(vector<vector<char>>& board) 
            {
                int posrow = 0, poscol = 0; //to store position of the rook
                
                for(int i = 0; i < 8; i++)
                {
                    int flag = 0;
                    for(int j = 0; j < 8; j++)
                    {
                        if(board[i][j]=='R')
                        {
                            posrow = i;
                            poscol = j;
                            flag = 1;
                            break;
                        }
                    }
                    if(flag==1) 
                        break;
                }
                
                int res = 0;

                //left
                for(int k=poscol-1; k>=0; k--)
                {
                    if(board[posrow][k]=='p')
                    {
                        res+=1; 
                        break;
                    }
                    else if(board[posrow][k]=='B') 
                        break;
                }

                //right
                for(int k = poscol+1; k<8; k++)
                {
                    if(board[posrow][k]=='p') 
                    {
                        res+=1; 
                        break;
                    }
                    else if(board[posrow][k]=='B') 
                        break;
                }

                //up
                for(int k = posrow-1; k>=0; k--)
                {
                    if(board[k][poscol]=='p') 
                    {
                        res+=1; 
                        break;
                    }
                    else if(board[k][poscol]=='B') 
                        break;
                }

                //down
                for(int k = posrow + 1; k<8; k++)
                {
                    if(board[k][poscol]=='p') 
                    {
                        res+=1; 
                        break;
                    }
                    else if(board[k][poscol]=='B') 
                        break;
                }

                return res;
            }
};