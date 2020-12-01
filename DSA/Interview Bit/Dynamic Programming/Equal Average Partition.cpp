int dp[101][101][1001];
bool lookforsubset(int i, vector<int> &A, vector<int> &temp, int sizereq, int sumreq)
{
    if (sizereq == 0)
        return dp[i][sizereq][sumreq] = sumreq == 0;

    if (i == A.size())
        return dp[i][sizereq][sumreq] = false;

    if (dp[i][sizereq][sumreq] != -1)
        return dp[i][sizereq][sumreq];

    if (A[i] <= sumreq)
    {
        temp.push_back(A[i]);

        if (lookforsubset(i + 1, A, temp, sizereq - 1, sumreq - A[i]))
            return dp[i][sizereq][sumreq] = true;
        temp.pop_back();
    }
    return dp[i][sizereq][sumreq] = lookforsubset(i + 1, A, temp, sizereq, sumreq);
}

vector<vector<int>> Solution::avgset(vector<int> &A)
{
    memset(dp, -1, sizeof(dp));
    /* 
    
        s1 is sum for partition x of size n1
        s2 is sum for partition y of size n2
        according to ques 
        
        s1/n1 = s2/n2
        
        now sum = s1+s2
        size = n1 + n2;
        hence sum-s1 = s2;
        size - n1 = n2;
        
        hence s1/n1 = (sum-s1)/(size-n1);
        s1*(size-n1) = (sum-s1)*n1
        s1 = (sum*n1)/size
        
        hence we put differnet value of n1 from 1 to size-1 (we have to divide in 2 parts)
        once we get an integer sum value for s1, we look for that sum subset in array
        if found then it is the minimum size subset
    
    */
    sort(A.begin(), A.end());

    int sumofarray = 0;

    for (int i = 0; i < A.size(); i++)
        sumofarray += A[i];

    vector<int> firsthalf;
    int flag = 0;

    for (int i = 1; i < A.size(); i++)
    {
        int temp = sumofarray * i;

        if (temp % A.size() == 0)
        {
            // we have to look for subset with sum as (temp/size) and
            // it's size should be 'i'

            if (lookforsubset(0, A, firsthalf, i, temp / A.size()))
            {
                flag = 1;
                break;
            }
            else
                firsthalf.clear();
        }
    }
    if (!flag)
        return {};

    unordered_map<int, int> mp;

    for (int i = 0; i < A.size(); i++)
        mp[A[i]]++;

    for (int i = 0; i < firsthalf.size(); i++)
        mp[firsthalf[i]]--;

    vector<int> secondhalf;
    for (int i = 0; i < A.size(); i++)
    {
        while (mp[A[i]])
        {
            secondhalf.push_back(A[i]);
            mp[A[i]]--;
        }
    }

    sort(firsthalf.begin(), firsthalf.end());
    sort(secondhalf.begin(), secondhalf.end());

    return {firsthalf, secondhalf};
}