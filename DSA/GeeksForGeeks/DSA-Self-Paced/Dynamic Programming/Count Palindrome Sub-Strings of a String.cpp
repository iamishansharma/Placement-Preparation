#include <bits/stdc++.h>
using namespace std;
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define debug(x)                          \
    {                                     \
        cerr << #x << " = " << x << endl; \
    }
#define ll long long int
#define mod 1000000007

void isPalindrome(string s, int mid_1, int mid_2, int &count)
{
    if (mid_1 == mid_2)
    {
        mid_1--;
        mid_2++;
    }

    while (mid_1 >= 0 && mid_2 < s.length() && s[mid_1] == s[mid_2])
    {
        count++;
        mid_1--;
        mid_2++;
    }
}

void solve()
{
    string s;

    int n = 0;
    cin >> n >> s;

    int count = 0;
    int i = 0;

    while (i < s.length())
    {
        isPalindrome(s, i, i, count);
        isPalindrome(s, i, i + 1, count);
        i++;
    }
    cout << count << endl;
}

int main()
{
    fastIO;

    int tc = 0;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}