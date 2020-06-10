// https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/

int Solution::solve(string A) 
{
    int n = A.size();
    string s, temp;
    int cnt = 0;
    
    do
    {
        s = A.substr(0,A.size()-cnt);
        temp = s;
        reverse(temp.begin(),temp.end());
        cnt++;
        
    }while(temp !=s && cnt!=n);
    
    return cnt-1;
}
