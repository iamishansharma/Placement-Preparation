int Solution::repeatedNumber(const vector<int> &A) 
{
    int tortoise=A[0],hare=A[0];
    while(true)
    {
        tortoise=A[tortoise];
        hare=A[A[hare]];
        if(tortoise==hare)
            break;
    }
    //stuck in infinite while loop if no duplicates
    //can be tweaked to get -1 in such cases, modify accordingly
    tortoise=A[0];
    while(tortoise!=hare)
    {
        tortoise=A[tortoise];
        hare=A[hare];
    }
    return tortoise;
}
