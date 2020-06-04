// https://www.interviewbit.com/problems/next-permutation/

vector<int> Solution::nextPermutation(vector<int> &nums) 
{
    if(nums.size() <= 1)
        return nums;
    
    int j=nums.size()-2;
    int i=nums.size()-1;
    
    for(; j>=0; j--)
    {
        if(nums[j] < nums[j+1])
            break;
    }
    
    if(j >= 0)
    {
        while(nums[i] <= nums[j])
            i--;
            
        swap(nums[i],nums[j]);
        
    }
    reverse(nums.begin()+j+1,nums.end());
    return nums;
}
