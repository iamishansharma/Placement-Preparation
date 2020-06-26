//https://www.interviewbit.com/problems/valid-number/

int Solution::isNumber(const string A) 
{
    int i=0;
    int len=A.length();
    int flag=0;
    
    while(A[i]==' ' && i<len)
        i++;
        
    while(i<len)
    {
        flag = 1;
        
        if((A[i]>='0' && A[i]<='9') || (A[i]=='.')||(A[i]=='-' && i==0)|| (A[i]==' '))
            i++;
        else if(A[i]=='e' && A[i-1]!='.')
        {
            i++;
            
            while(A[i]!='.' && i<len)
                i++;
                
            if(i!=len)
                return 0;
        }
        else
            return 0;
    }
    
    if(A[i-1]!='.' && flag)
        return 1;
        
    return 0;
}