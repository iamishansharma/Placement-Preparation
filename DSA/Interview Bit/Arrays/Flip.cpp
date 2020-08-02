vector<int> Solution::flip(string A) 
{
    long long int sum_so_far = 0, sum_ending_here = 0;
    
    int i=0, j=0, start = -1, end = -1;
    
    for(i=0; i<A.size(); i++)
    {
        sum_ending_here += (A[i]=='1')? -1:1;
        
        if(sum_so_far < sum_ending_here)
        {
            sum_so_far = sum_ending_here;
            start = j;
            end = i;
        }
        if(sum_ending_here < 0)
        {
            j = i+1;
            sum_ending_here = 0;
        }
    }
    
    vector<int> ans;
    
    if(sum_so_far)
    {
        ans.push_back(start+1);
        ans.push_back(end+1);
    }
    return ans;
}
