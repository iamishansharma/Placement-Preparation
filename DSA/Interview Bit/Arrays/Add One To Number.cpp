vector<int> Solution::plusOne(vector<int> &A) 
{
    A[A.size()-1]++;

    int lastDigit=0;
    int firstDigit=0;
    int i=0;

    if(A.size() == 1 && A[0]>9)
    {
        firstDigit =   A[0]/10;
        lastDigit = A[0]%10;
        
        A[0] = lastDigit;
        A.insert(A.begin(),firstDigit);
    }
    else
    {   
        i=A.size()-1;
        lastDigit=0;
        firstDigit=0;
        
        while(i>0)
        {
            if(firstDigit>0)
            {
                A[i] = A[i] + firstDigit;
                firstDigit=0;
            }
            if(A[i]>9)
            {
                firstDigit =   A[i]/10;
                lastDigit = A[i]%10;
                
                A[i] = lastDigit;
            }
            if(firstDigit == 0)
            {
                break;
            }
            i--;
        }
        if(firstDigit>0)
        {
            A[0] = A[0] + firstDigit;
            if(A[0]>9)
            {
                firstDigit =   A[0]/10;
                lastDigit = A[0]%10;
                
                A[0] = lastDigit;
                A.insert(A.begin(),firstDigit);
            }
        }
    }

    i=0;
    
    while(A[i] == 0)
        A.erase(A.begin() + i);
        
    return A;
}
