vector<int> Solution::findPerm(const string A, int B) 
{
    vector<int> ans;
    int i = 1, j = B;
    int k = 0;
    
    while(i<j)
    {
        if(A[k++]=='I')
            ans.push_back(i++);
        else
            ans.push_back(j--);
    }
    ans.push_back(i++);
    return ans;
}