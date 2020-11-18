// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

long long sumSubstrings(string);

int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //taking string
        string s;
        cin >> s;

        //calling sumSubstrings() function
        cout << sumSubstrings(s) << endl;
    }
    return 0;
}
// } Driver Code Ends

// function to find sum of all possible substrings of the given string
long long sumSubstrings(string s)
{
    long long prev_res = s[0] - '0';
    long long res = prev_res;

    for (int i = 1; i < s.size(); i++)
    {
        prev_res = ((i + 1) * (s[i] - '0') + 10 * prev_res) % 1000000007;
        res = (res + prev_res) % 1000000007;
    }

    return res;
}
