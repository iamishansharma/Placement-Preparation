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
    int v = 0;
    cin >> v;

    vector<vector<int>> dist(v, vector<int>(v));

    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            cin >> dist[i][j];

    for (int k = 0; k < v; k++)
        for (int i = 0; i < v; i++)
            for (int j = 0; j < v; j++)
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            if (dist[i][j] == 10000000)
                cout << "INF"
                     << " ";
            else
                cout << dist[i][j] << " ";
        cout << endl;
    }
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