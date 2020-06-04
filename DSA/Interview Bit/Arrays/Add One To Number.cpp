// https://www.interviewbit.com/problems/add-one-to-number/

vector<int> Solution::plusOne(vector<int> &v) 
{
    while(v[0]==0 && v.size() > 0)
    {
        v.erase(v.begin());
    }
    for(int i = v.size() - 1; i >= 0; i--) 
    { 
        if(v[i] != 9) 
        {
            v[i]++;
            return v;
        } 
        v[i] = 0;
    }
    v.insert(begin(v), 1);
    return v;
}
