// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

bool isPrime(int n)
{
    if (n == 0 || n == 1)
        return false;

    if (n == 2 || n == 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || (n % (i + 2) == 0))
            return false;

    return true;
}

// { Driver Code Starts.

int main()
{
    int T;      //testcases
    cin >> T;   //input testcases
    while (T--) //while testcase have not been exhausted
    {
        int N;
        cin >> N; //input n

        if (isPrime(N))
            cout << "Yes";
        else
            cout << "No";

        cout << endl;
    }
    return 0;
}
// } Driver Code Ends