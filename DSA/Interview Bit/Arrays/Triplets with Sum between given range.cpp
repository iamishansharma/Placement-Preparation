// https://www.interviewbit.com/problems/triplets-with-sum-between-given-range/

int Solution::solve(vector<string> &A) 
{
    int n = A.size();
    if(n<3)
        return 0;
        
    vector<float> a,b,c;
    
    for(int i=0;i<n;i++)
    {
        float f = stof(A[i]);
        
        if(f < 2.0/3)
            a.push_back(f);
        else if(f < 1)
            b.push_back(f);
        else if(f < 2)
            c.push_back(f);
            
    } 
    
    int n1=a.size(),n2=b.size(),n3=c.size();
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    
    if(n1 && n2 && n3)
        if(a[0] + b[0] + c[0] < 2)
            return 1;
    
    if(n1 > 2 && a[n1-1] + a[n1-2] + a[n1-3] > 1)
        return 1;
    
    if(n1 > 1 && n3 && a[0]+a[1]+c[0] < 2)
        return 1;
    
    if(n2 > 1 && n1 && b[0] + b[1] + a[0] < 2)
        return 1;
    
    for(int i=0;i<n2;i++)
    {
        float sum = b[i];
        int s = 0, e = n1-1;
        
        while(s<e)
        {
            float d = a[s] + a[e] + sum;
            
            if(d>1&&d<2)
                return 1;
                
            else if(d>2)
                e--;
            else if(d<1)
                s++;
        }
    }
    return 0;
}
