// https://www.interviewbit.com/problems/maxspprod/

int Solution::maxSpecialProduct(vector<int> &A) 
{
    long int lsv = 0;
    long int rsv = 0;
    long int max =0;
    int start =0;
    int end = 0;
    int flag = 0;
    
    for(int end=1; end<A.size()-1; end++)
    {
        if (A[start]>A[end])
        {
            lsv = start;
            flag = 1;
        }
        if(A[end-1]>A[end])
        {
            start = end-1;
            lsv = start;
            flag = 1;
        }
        if(flag ==0) 
        {
            start = start+1;
        }
        
        if (A[end+1]>A[end])
        {
                rsv = end+1;
        }
        
        if(lsv*rsv >max)
        {
            max = lsv*rsv;
        }
        
        lsv = 0;
        rsv = 0;
        flag =0;
    }
    
    return (int) (max % 1000000007);
}
