// https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/

vector<int> Solution::getRow(int n) 
{
    vector<int> ans(n+1);
    ans[0]=1;
    for(int i=0;i<=n/2;i++)
    {
        ans[i+1] = ((n-i)*ans[i])/(i+1);
        ans[n-i] = ans[i];
    }
    return ans;
}
