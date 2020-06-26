//https://www.interviewbit.com/problems/implement-strstr/

int Solution::strStr(const string A, const string B) 
{
    if(A.length()==0 || B.length()==0)
        return -1;
        
    for(int i=0; i<A.length(); i++)
    {
        int j=i;
        int k=0;
        while(A[j]==B[k] && k<B.length() && j<A.length())
        {
            j++;
            k++;
        }
        if(k==B.length())
            return i;
            
        if(j==A.length())
            return -1;
    }
    return -1;
}