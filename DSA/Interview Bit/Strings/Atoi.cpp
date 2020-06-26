//https://www.interviewbit.com/problems/atoi/

int Solution::atoi(const string A) 
{
    int i = 0;
    bool negative = false;
    
    while(A[i] == ' ') 
        i++;
        
    if(A[i] == '-')
    {
        negative = true;
        i++;
    }
    else if(A[i] == '+') 
        i++;
        
    long num = 0;
    
    for(int j=i; j<A.size(); j++)
    {
        if(A[j] <= '9' and A[j] >= '0')
        {
            num = num*10 + A[j] - '0';
            
            if(num>INT_MAX) 
                return negative ? INT_MIN : INT_MAX;
        }
        else
            return negative ? -1 * num : num;
    }
    
    if(num>INT_MAX) 
        return negative ? INT_MIN : INT_MAX;
        
    return negative ? -1 * num : num;
}
