int Solution::candy(vector<int> &A)
{
    int arr[A.size()];

    for (int i = 0; i < A.size(); i++)
        arr[i] = 1;

    for (int i = A.size() - 2; i >= 0; i--) //in one iteration adding 1 to a numbered index if it is greater
    {
        if (i != A.size() - 1 && A[i] > A[i + 1])
            arr[i] = arr[i + 1] + 1;
    }
    for (int i = 1; i < A.size(); i++) //now to minimise number of toffees choosing next+1 or itself(if number of tofees is already greater)
    {
        if (i != 0 && A[i] > A[i - 1])
            arr[i] = max(arr[i - 1] + 1, arr[i]);
    }

    int count = 0;

    for (int i = 0; i < A.size(); i++)
        count += arr[i];

    return count;
}
