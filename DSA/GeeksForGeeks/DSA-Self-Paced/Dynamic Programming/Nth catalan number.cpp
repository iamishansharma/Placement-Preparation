// { Driver Code Starts
//Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int; // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;

cpp_int findCatalan(int);

int main()
{
    //taking count of testcases
    int t;
    cin >> t;
    while (t--)
    {

        //taking nth number
        int n;
        cin >> n;

        //calling function findCatalan function
        cout << findCatalan(n) << "\n";
    }
    return 0;
} // } Driver Code Ends

//User function template for C++

// n : given integer value
cpp_int findCatalan(int n)
{
    cpp_int dp[n + 1] = {0};

    dp[0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            dp[i] += dp[j] * dp[i - j - 1];

    return dp[n];
}