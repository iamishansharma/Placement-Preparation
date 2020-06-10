// https://www.interviewbit.com/problems/amazing-subarrays/

int Solution::solve(string A) 
{
    int total = 0;
    
    for(int i=0; i<A.length(); i++)
    {
        if(A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u' || A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U')
        {
            total += A.length() - i;
        }
    }
    return total % 10003;
}
