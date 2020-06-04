// https://www.interviewbit.com/problems/maximum-consecutive-gap/

int Solution::maximumGap(const vector<int> &A) 
{
    int n = A.size();
    
    if(n < 2) 
        return 0;
        
    auto lu = minmax_element(A.begin(), A.end());
    int l = *lu.first, u = *lu.second;
        
    int gap = max(1, (u-l)/(n-1));
    int m = (u-l)/gap + 1;
    
    vector<int> mini(m, INT_MAX), maxi(m, INT_MIN);
    
    for(int i=0; i<n; i++)
    {
        int k = (A[i] - l)/gap;
        mini[k] = min(mini[k], A[i]);
        maxi[k] = max(maxi[k], A[i]);
    }
    int prev = l;
    int res = INT_MIN;
    for (int i=0; i<m; i++)
    {
        if(mini[i] == INT_MAX) 
            continue;
            
        res = max(res, mini[i]- prev);
        prev = maxi[i];
    }
    res = max(res, u-prev);
    return res;
}
