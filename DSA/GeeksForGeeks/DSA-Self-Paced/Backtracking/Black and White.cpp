#include <iostream>
using namespace std;

int unSafe(int i, int j, int n, int m)
{
    int dx[] = {i + 1, i + 1, i + 2, i + 2, i - 1, i - 1, i - 2, i - 2};
    int dy[] = {j + 2, j - 2, j + 1, j - 1, j + 2, j - 2, j - 1, j + 1};

    int unsafe = 0;

    for (int k = 0; k < 8; k++)
        if (dx[k] < n && dx[k] >= 0 && dy[k] < m && dy[k] >= 0)
            unsafe++;

    return unsafe;
}

int main()
{
    int tc = 0;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;

        long long int ans = 0;
        int total = n * m;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans += total - unSafe(i, j, n, m) - 1;

        cout << ans << endl;
    }
    return 0;
}
