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

void solve()
{
    int n = 0;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k = 0;
    cin >> k;

    sort(arr.begin(), arr.end(), greater<int>());

    int sum = 0;

    // 17 15 12 10 9 5 3

    for (int i = 0; i < n; i++)
    {
        if (i + 1 < n && arr[i] - arr[i + 1] < k)
        {
            sum += arr[i] + arr[i + 1];
            i++;
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