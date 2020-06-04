// https://www.interviewbit.com/problems/find-duplicate-in-array/

int Solution::repeatedNumber(const vector<int> &nums) 
{
    int torotoise = nums[0];
    int hare = nums[0];
    
    while(true)
    {
        torotoise = nums[torotoise];
        hare = nums[nums[hare]];
    
        if(torotoise==hare)
            break;
    }
    int ptr1 = nums[0];
    int ptr2 = torotoise;
    
    while(ptr1 != ptr2)
    {
        ptr1=nums[ptr1];
        ptr2=nums[ptr2];
    }
    return ptr1;
}