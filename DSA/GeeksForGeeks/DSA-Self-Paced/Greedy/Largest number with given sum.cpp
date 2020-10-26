// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to return Largest Number
string largestNumber(int n, int sum)
{
    if (sum > 9 * n)
        return "-1";

    string ans = "";

    while (sum != 0)
    {
        if (sum > 9)
        {
            sum -= 9;
            ans += '9';
        }
        else
        {
            ans += to_string(sum);
            sum -= sum;
        }
    }

    if (ans.size() != n)
        while (ans.size() != n)
            ans += '0';

    return ans;
}

// { Driver Code Starts.
int main()
{
    //taking testcases
    int t;
    cin >> t;

    while (t--)
    {
        //taking n and sum
        int n, sum;
        cin >> n >> sum;

        //function call
        cout << largestNumber(n, sum) << endl;
    }
    return 0;
} // } Driver Code Ends