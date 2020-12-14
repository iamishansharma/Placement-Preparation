// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

// Function to count set bits in the given number x
// n: input to count the number of set bits

int countSetBits(int n)
{
    int sum = 0;

    while (n)
    {
        int power = floor(log2(n));
        int num = pow(2, power);
        sum += num * power / 2 + (n - num + 1);
        n -= num;
    }
    return sum;
}

// { Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t;   // input testcases
    while (t--) //while testcases exist
    {
        int n;
        cin >> n; //input n

        cout << countSetBits(n) << endl; // print the answer
    }
    return 0;
}
// } Driver Code Ends