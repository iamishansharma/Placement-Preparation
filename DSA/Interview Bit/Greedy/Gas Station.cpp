// https://www.interviewbit.com/problems/gas-station/

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) 
{
    int total_gas=0;
    int total_dis=0;
    int start_index=0;
    int remaining_cap=0;
    
    for(int i=0;i<A.size();i++)
    {
        int g = A[i];
        int d =B[i];
        
        remaining_cap+=(g-d);
        
        if(remaining_cap<0)
        {
            remaining_cap =0;
            start_index=i+1;
        }
        total_gas+=g;
        total_dis+=d;
    }
    
    if(total_gas<total_dis)
        return -1;
        
    return start_index;
}
