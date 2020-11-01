// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long solve(int n, int m);

int main()
{
    // code
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        cout << solve(n, m) << endl;
    }
    return 0;
} // } Driver Code Ends

long long solve(int N, int M)
{
    int sub_res = 1;
    int total = M * N;
    long long res = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {

            if (i - 2 >= 0 && j + 1 < M)
                sub_res++;
            if (i - 1 >= 0 && j + 2 < M)
                sub_res++;
            if (i + 1 < N && j + 2 < M)
                sub_res++;
            if (i + 2 < N && j + 1 < M)
                sub_res++;
            if (i + 2 < N && j - 1 >= 0)
                sub_res++;
            if (i + 1 < N && j - 2 >= 0)
                sub_res++;
            if (i - 1 >= 0 && j - 2 >= 0)
                sub_res++;
            if (i - 2 >= 0 && j - 1 >= 0)
                sub_res++;

            res = (res + total - sub_res) % 1000000007;
            sub_res = 1;
        }
    }

    return res;
}