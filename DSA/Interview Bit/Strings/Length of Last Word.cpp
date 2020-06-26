// https://www.interviewbit.com/problems/length-of-last-word/

int Solution::lengthOfLastWord(const string A) 
{
    int count = 0;
    int i = A.size()-1;
    
    while(A[i] == ' ')
        i--;
        
    while(A[i] != ' ' && i>=0)
    {
        count++;
        i--;
    }
    return count;
}
