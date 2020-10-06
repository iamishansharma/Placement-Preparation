// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

void print(vector<vector<int>> arr, int row, int col) {

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
    }
    cout << "\n";
}

vector <vector <int> > nearest(vector<vector<int>> &arr, int row, int col);
int main() {

    int tc;
    cin >> tc;
    while (tc--) {
        int row, col;
        cin >> row >> col;

        // Input matrix is represented using vectors of vectors
        vector<vector<int>> graph(row, vector<int>(col, 0));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> graph[i][j];
            }
        }

        print (nearest(graph, row, col), row, col);
    }

    return 0;
}
// } Driver Code Ends


/*  Function to find the distance of nearest cell having 1

*   mat: The input matrix of 0s and 1s
*   N, M: rows and cols in given matrix
*   Return the resultant matrix of size (N x M) representing the nearest distance 1 from each cell
*/
void bfs(vector<vector<int>> &mat, vector<vector<int>> &dist, int row, int col)
{
    // Refer to the video Shortest DAG using Topological Sorting and Relaxation
    
    queue<pair<int,int>> q;
    
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(mat[i][j] == 1)
            {
                dist[i][j] = 0;
                q.push({i,j});
            }
        }
    }
    
    int xdir[4] = {0, 0, -1, 1};
    int ydir[4] = {-1, 1, 0, 0};
    
    while(!q.empty())
    {
        pair<int,int> temp = q.front();
        q.pop();
        
        for(int k=0; k<4; k++)
        {
            int newx = temp.first + xdir[k];
            int newy = temp.second + ydir[k];
            
            if(newx >= 0 && newy >=0 && newx < row && newy < col && dist[newx][newy] > dist[temp.first][temp.second] + 1) // Relaxation
            {
                dist[newx][newy] = dist[temp.first][temp.second] + 1;
                q.push({newx, newy});
            }
        }
    }
}
 
vector<vector<int>> nearest(vector<vector<int>> &mat, int row, int col) 
{
    vector<vector<int>> dist(row, vector<int> (col, INT_MAX));
    
    bfs(mat, dist, row, col);

    return dist;
}