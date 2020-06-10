// https://www.interviewbit.com/problems/count-and-say/

string Solution::countAndSay(int A) 
{
    string s="1";
    string ans="";
    A--;
    
    while(A--)
    {
        int i = 0;
        int j = i+1;
        
        while(i<s.length())
        {
            int j = i+1;
            int count = 1;
            
            while(j<s.length() && s[j] == s[i])
            {
                count++;
                j++;
            }
            ans += to_string(count) + s[i];
            i = j;
        }
        s = ans;
        ans = "";
    }
    return s;
}
