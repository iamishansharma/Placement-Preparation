void Solution::rotate(vector<vector<int> > &mat) 
{
    for(int i=0; i<mat.size(); i++)
        for(int j=i+1; j<mat[i].size(); j++)
            swap(mat[i][j], mat[j][i]);
    
    for(int i=0; i<mat.size(); i++)
        for(int j=0; j<mat[i].size()/2; j++)
            swap(mat[i][j], mat[i][mat[i].size()-1-j]);
}
