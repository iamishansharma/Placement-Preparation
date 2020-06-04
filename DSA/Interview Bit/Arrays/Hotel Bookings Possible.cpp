// https://www.interviewbit.com/problems/hotel-bookings-possible/

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) 
{
    sort(arrive.begin(),arrive.end());
    sort(depart.begin(),depart.end());
    
    for (int i = K; i < arrive.size(); i++)
    {
        if(arrive[i] < depart[i-K])
            return false;
    }
    return true;
}