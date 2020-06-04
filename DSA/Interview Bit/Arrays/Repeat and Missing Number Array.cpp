// https://www.interviewbit.com/problems/repeat-and-missing-number-array/

vector<int> Solution::repeatedNumber(const vector<int> &A) 
{
    long long sum=0;
    long long sum2=0;
    for (int i = 0 ; i <A.size();i++)
    {
        sum = sum + A[i] - long(i+1);
        sum2 = sum2 + long(A[i])*long(A[i])-long(i+1)*long(i+1);
        
    }
    int m = ((sum*sum) + sum2)/(2*sum);
    int r = abs(sum-m);
    return vector {m, r};
}
