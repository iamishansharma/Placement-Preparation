int Solution::maximumGap(const vector<int> &a) 
{
    if(a.size() < 2)
        return 0;
        
    int mn = INT_MAX, mx = INT_MIN;
    
    for(int i=0;i<a.size();i++)
    {
        mn=min(mn,a[i]);
        mx=max(mx,a[i]);
    }
    
    int gap = sqrt(mx-mn+1);
    int k = ceil(1.0*(mx-mn+1)/gap);
    
    vector<int> mna(k,INT_MAX),mxa(k,INT_MIN);
    
    for(int i=0;i<a.size();i++)
    {
        int index=(a[i]-mn)/gap;
        mna[index] = min(a[i],mna[index]);
        mxa[index] = max(a[i],mxa[index]);
    }
    
    int ans=0,pre = mn;
    
    for(int i=0;i<k-1;i++)
    {
        if(mna[i] == INT_MAX)
            continue;
            
        ans = max(ans,mna[i]-pre);
        pre = mxa[i];
    }
    ans = max(ans,mx-pre);
    return ans;
}
