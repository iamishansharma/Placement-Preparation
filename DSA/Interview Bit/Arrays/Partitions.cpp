int Solution::solve(int n, vector<int> &arr) 
{
    long long pre = 0;
    long long index [n+1] = {0};
    
    for(int i=0;i<n;i++)
        pre += arr[i];
        
    if(pre%3 != 0)
        return 0;
        
    long long sf = 0;
    
    for(int i=n-1; i>=0; i--)
    {
        sf += arr[i];
       
        if(sf == (pre/3))
            index[i] = 1;
    }
    
    for(int i=0;i<n;i++)
        index[i] = index[i-1] + index[i];

    long long pree=0,ans=0;
    pre = pre/3;
    
    for(int i=0; i<n-1; i++)
    {
        pree += arr[i];
        
        if(pree == pre)
          ans += index[n-1]-index[i+1];
    }
    return ans;
}
