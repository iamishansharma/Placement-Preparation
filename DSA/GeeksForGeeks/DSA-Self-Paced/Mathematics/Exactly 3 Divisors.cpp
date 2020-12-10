// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

bool isPrime(int N)
{
    for (int i = 2; i <= sqrt(N); i++)
        if (N % i == 0)
            return false;

    return true;
}
int exactly3Divisors(int n)
{
    int cnt = 0;

    for (int i = 2; i <= sqrt(n); i++)
        if (isPrime(i))
            cnt++;

    return cnt;
}

// { Driver Code Starts.

int main()
{
    int T;

    //taking testcases
    cin >> T;
    while (T--)
    {
        int N;

        //taking N
        cin >> N;

        //calling function exactly3Divisors()
        cout << exactly3Divisors(N) << endl;
    }
    return 0;
} // } Driver Code Ends