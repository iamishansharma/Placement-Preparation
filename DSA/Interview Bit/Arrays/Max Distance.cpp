//https://www.interviewbit.com/problems/max-distance/

int Solution::maximumGap(const vector<int> &A) 
{
    vector<int> max_arr(A.size());
    vector<int> min_arr(A.size());
    
    int n = A.size();
    
    max_arr[n-1] = A[n-1];
    
    for(int i  = n-2 ; i>=0 ; i--)
        max_arr[i] = max(A[i],max_arr[i+1]);
    
    min_arr[0]  =A[0];
    
    for(int i = 1;i< n ; i++)
        min_arr[i] = min(min_arr[i-1], A[i]);
    
    int i = 0;
    int j =0;
    
    int ans  = 0;
    
    while(i<n && j<n)
    {
        if(min_arr[i] <= max_arr[j])
            ans = max(ans, (j++)-i);
        else
            i++;
    }
    return ans;
}
