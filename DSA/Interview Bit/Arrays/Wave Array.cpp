// https://www.interviewbit.com/problems/wave-array/

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

vector<int> Solution::wave(vector<int> &A) 
{
    if(A.size() == 0 || A.size() == 1)
        return A;
    
    sort(A.begin(), A.end());
   
    for(int i=0; i <= A.size()-2; i=i+2)
        swap(A[i],A[i+1]);
        
    return A;
}
