// https://www.interviewbit.com/problems/assign-mice-to-holes/

int Solution::mice(vector<int> &a, vector<int> &b) 
{
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    int ans = INT_MIN;
    int n = a.size();
    
    for(int i=0; i<n; i++)
        ans = max(ans,abs(a[i]-b[i]));
        
    return ans;
}
