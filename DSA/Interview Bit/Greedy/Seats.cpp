// https://www.interviewbit.com/problems/seats/

int Solution::seats(string A) 
{
    vector<int> pts;
    
    for (int i = 0; i < A.size(); i++)
        if (A[i] == 'x')
            pts.push_back(i);
            
    int mid = pts.size()/2;
    int res = 0;
    
    for (int i = 0; i < pts.size(); i++) 
    {
        int start = pts[i];
        int dest = pts[mid] - (mid - i);
        res = (res + abs(dest - start)) % 10000003;
    }
    return res;
}
