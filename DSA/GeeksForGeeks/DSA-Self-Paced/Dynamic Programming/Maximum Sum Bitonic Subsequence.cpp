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

    vector<int> left(n, 0);
    vector<int> right(n, 0);

    left[0] = arr[0];

    int localmax = 0;

    for (int i = 1; i < n; i++)
    {
        localmax = 0;

        for (int j = 0; j < i; j++)
            if (arr[j] < arr[i])
                localmax = max(localmax, left[j]);

        left[i] = localmax + arr[i];
    }

    right[n - 1] = arr[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        localmax = 0;

        for (int j = n - 1; j > i; j--)
            if (arr[j] < arr[i])
                localmax = max(localmax, right[j]);

        right[i] = localmax + arr[i];
    }

    // for(int i=0; i<n; i++)
    //     cout<<left[i]<<" ";
    // cout<<endl;

    // for(int i=0; i<n; i++)
    //     cout<<right[i]<<" ";
    // cout<<endl;

    int globalmax = INT_MIN;

    for (int i = 0; i < n; i++)
        globalmax = max(globalmax, left[i] + right[i] - arr[i]);

    cout << globalmax << endl;
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