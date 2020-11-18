// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll count(ll n);

int main()
{
    //taking total testcases
    int t;
    cin >> t;

    while (t--)
    {
        //taking the score
        ll n;
        cin >> n;

        //calling function count()
        cout << count(n) << "\n";
    }
    return 0;
} // } Driver Code Ends

//User function tempate for C++

// n :  given score

ll count(ll n)
{
    int table[n + 1] = {0};

    table[0] = 1;

    vector<int> nums = {3, 5, 10};

    for (int num : nums)
        for (int i = num; i <= n; i++)
            table[i] += table[i - num];

    return table[n];
}