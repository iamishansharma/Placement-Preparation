// https://www.interviewbit.com/problems/maximum-absolute-difference/

int Solution::maxArr(vector<int> &A) 
{
    if(A.size()==1)
        return 0;
        
    int sum=0;
    int sum1=0;
    
    int maxi=INT_MIN;
    int maxii=INT_MIN;
    int minj=INT_MAX;
    int minjj=INT_MAX;
    
    for(int i =0; i <A.size();i++)
    {
        sum = (A[i]+i); 
        sum1 = (A[i]-i);
        
        if (maxi<sum) 
            maxi=sum;
            
        if (maxii<sum1) 
            maxii=sum1;
        
        if (minj>sum) 
            minj=sum;
            
        if(minjj>sum1) 
            minjj=sum1;    
    }      
    return max(abs(maxi-minj),abs(maxii-minjj));
}
