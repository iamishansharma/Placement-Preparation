// https://www.interviewbit.com/problems/largest-number/

bool comp(int a, int b)
{
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

string Solution::largestNumber(const vector<int> &A) 
{
    int n = A.size();
    vector<int> v;

    for(int i=0; i<n; i++)
    {
        int x = A[i];
        v.push_back(x);
    }

    sort(v.begin(),v.end(),comp);

    if(v[0] == 0)
        return "0";
    
    string s = to_string(v[0]);
    
    for(int i=1;i<n;i++)
        s.append(to_string(v[i]));
        
    return s;
}