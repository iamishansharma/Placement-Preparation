// https://www.interviewbit.com/problems/palindrome-string/

int Solution::isPalindrome(string A) 
{
    string ans="";

    for(int i=0;i<A.length();i++)
    {
        if('a'<=A[i]  && A[i]<='z')
            ans+=A[i];
        
        if('A'<=A[i] && A[i]<='Z')
            ans+=A[i]-'A'+'a';
        
        if('0'<=A[i]  && A[i]<='9')
            ans += A[i];
    }
    
    int len = ans.length()-1;
    
    for(int i=0; i<=len/2; i++)
    {
        if(ans[i] != ans[len-i])
            return 0;
    }
    return 1;
}
