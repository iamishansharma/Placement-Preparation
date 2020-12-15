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

void solve()
{
    int n = 0;
    cin >> n;

    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k = 0;
    cin >> k;

    sort(arr.begin(), arr.end());

    int i = n - 1, j = n - 2;

    int sum = 0;

    while (i >= 0 && j >= 0)
    {
        if (arr[i] - arr[j] < k)
        {
            sum += arr[i] + arr[j];
            i = i - 2;
            j = j - 2;
        }
        else
        {
            i--;
            j--;
        }
    }

    cout << sum << endl;
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