vector<int> Solution::repeatedNumber(const vector<int> &A) 
{
    long n = A.size();
    long S1 = 0, S2 = 0;
    for(int i:A)
    {
        S1 += i;
        S2 += ((long)i)*i;
    }
    
    long E1 = n*(n+1)/2;
    long E2 = n*(n+1)*(2*n+1)/6;
    
    long D1 = S1-E1;
    long D2 = S2-E2;
    
    long DIF = D1;
    long SUM = D2/D1;
    
    long repeat = (SUM+DIF)/2;
    long miss = (SUM-DIF)/2;
    
    return {(int)repeat,(int)miss};
}
