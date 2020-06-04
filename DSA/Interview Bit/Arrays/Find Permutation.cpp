// https://www.interviewbit.com/problems/find-permutation/

vector<int> Solution::findPerm(const string a, int b) 
{
    int strt = 1, end=b;
    vector<int> v;
    
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]=='I')
        { 
            v.push_back(strt);
            strt++;
        }
        
        else if(a[i] == 'D')
        { 
            v.push_back(end);
            end--;    
        }
    }
    v.push_back(strt);
    return v;
}
