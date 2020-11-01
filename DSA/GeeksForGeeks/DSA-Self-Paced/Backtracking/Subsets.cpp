// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

void helper(vector<int> A, int idx, int n, vector<int> temp, vector<vector<int>> &res)
{
    res.push_back(temp);

    for (int i = idx; i < n; i++)
    {
        if (i == idx || A[i] != A[i - 1])
        {
            temp.push_back(A[i]);

            helper(A, i + 1, n, temp, res);

            temp.pop_back();
        }
    }
}

vector<vector<int>> AllSubsets(vector<int> A, int n)
{
    vector<vector<int>> res;
    sort(A.begin(), A.end());

    helper(A, 0, n, vector<int>{}, res);

    return res;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> A;
        int x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            A.push_back(x);
        }

        vector<vector<int>> result = AllSubsets(A, n);
        // printing the output
        for (int i = 0; i < result.size(); i++)
        {
            cout << '(';
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j];
                if (j < result[i].size() - 1)
                    cout << " ";
            }
            cout << ")";
        }
        cout << "\n";
    }
}

// } Driver Code Ends