// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <fstream>
using namespace std;

long long findNthFibonacci(int number);

// } Driver Code Ends

//User function Template for C++
// You need to complete this function

// Return the number-th Fibonacci
long long findNthFibonacci(int number)
{
    long long fib[number + 2];

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= number; i++)
        fib[i] = fib[i - 2] + fib[i - 1];

    return fib[number];
}

// { Driver Code Starts.

int main()
{
    //taking testcases
    int testcases;
    cin >> testcases;

    while (testcases--)
    {
        //taking nth fibonacci
        //to be found
        int number;
        cin >> number;

        //calling function findNthFibonacci()
        //and passing number as parameter
        cout << findNthFibonacci(number) << endl;
    }

    return 0;
}
// } Driver Code Ends