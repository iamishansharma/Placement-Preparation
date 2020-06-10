// https://www.interviewbit.com/problems/majority-element/

int Solution::majorityElement(const vector<int> &A) 
{
    map<int,int> m;
    
    for(auto i:A)
        m[i]++;
    
    for(auto i:m)
    {
        if(i.second > A.size()/2)
            return i.first;
    }
    return -1;
}
