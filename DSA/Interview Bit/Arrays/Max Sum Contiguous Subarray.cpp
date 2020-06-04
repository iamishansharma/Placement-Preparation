// https://www.interviewbit.com/problems/max-sum-contiguous-subarray/

int Solution::maxSubArray(const vector<int> &v) 
{
    int n=v.size();
    int sum=0;
    int m=INT_MIN;
    
    for(int i=0;i<n;i++)
    {
        sum += v[i];
        m = max(sum,m);
        
        if(sum<0)
            sum = 0;
    }
    return m;
}
