bool comp(string a, string b)
{
    return a+b > b+a;    
}

string Solution::largestNumber(const vector<int> &A) 
{
    int n = A.size();
    
    vector<string> nums(n);
    
    int count_zeros = 0;
    
    for(int i=0; i<n; i++)
    {
        nums[i] = to_string(A[i]);
        
        if(A[i] == 0)
            count_zeros++;
    }
    
    if(count_zeros == n)
        return "0";
    
    sort(nums.begin(), nums.end(), comp);
    
    string ans = "";
    
    for(int i=0; i<n; i++)
        ans += nums[i];
        
    return ans;
}
