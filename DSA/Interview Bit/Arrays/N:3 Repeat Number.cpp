// https://www.interviewbit.com/problems/n3-repeat-number/

int Solution::repeatedNumber(const vector<int> &A) 
{
    int n=A.size();
    int count1 = 0, count2 = 0;
    int first=INT_MAX , second=INT_MAX ;
    
    for (int i = 0; i < n; i++) 
    {
        if (first == A[i]) 
            count1++; 
    
        else if (second == A[i]) 
            count2++; 
      
        else if (count1 == 0) 
        { 
            count1++; 
            first = A[i]; 
        } 
    
        else if (count2 == 0) 
        { 
            count2++; 
            second = A[i]; 
        } 

        else 
        { 
            count1--; 
            count2--; 
        } 
    } 
    
    count1 = 0; 
    count2 = 0; 

    for (int i = 0; i < n; i++) 
    { 
        if (A[i] == first) 
            count1++; 
    
        else if (A[i] == second) 
            count2++; 
    } 
    
    if (count1 > n / 3) 
        return first; 
    
    if (count2 > n / 3) 
        return second; 
    
    return -1; 
}
