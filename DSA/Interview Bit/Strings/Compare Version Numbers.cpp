//https://www.interviewbit.com/problems/compare-version-numbers/

int Solution::compareVersion(string string1, string string2) 
{
    int i = 0; 
    int j = 0;
    
    long long n1 = string1.size(); 
    long long n2 = string2.size();
    
    unsigned long long num1 = 0;
    unsigned long long num2 = 0;
    
    while(i<n1 || j<n2)
    {
        while(i<n1 && string1[i]!='.')
        {
            num1 = num1*10+(string1[i]-'0');
            i++;
        }
        
        while(j<n2 && string2[j]!='.')
        {
            num2 = num2*10+(string2[j]-'0');;
            j++;
        }
        
        if(num1>num2) 
            return 1;
        else if(num1 < num2) 
            return -1;
        
        num1 = 0;
        num2 = 0;
        i++;
        j++;
    }
    
    return 0;
}