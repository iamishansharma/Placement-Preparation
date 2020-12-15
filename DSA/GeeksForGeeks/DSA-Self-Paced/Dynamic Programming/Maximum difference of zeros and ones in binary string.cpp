// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function template for C++
class Solution
{
public:
    int maxSubstring(string S)
    {
        int n = S.length();
        int A[n];

        for (int i = 0; i < n; i++)
        {
            if (S[i] == '1')
                A[i] = -1;
            else
                A[i] = 1;
        }

        int temp = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            temp += A[i];
            ans = max(ans, temp);
            temp = max(temp, 0);
        }

        if (ans == 0)
            return -1;

        return ans;
    }
};

// { Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;

        cout << ob.maxSubstring(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends