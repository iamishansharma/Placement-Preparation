// https://www.interviewbit.com/problems/bulbs/

int Solution::bulbs(vector<int> &A) 
{
    int curron = 1;
    int count = 0;
    
    for(int i : A)
    {
        if(i != curron)
        {
            count++;
            curron = i;
        }
    }
    return count;
}
