// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

string mostFrequentWord(string arr[], int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << mostFrequentWord(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends

// User function template for C++

// arr : given array of string
// n : number of string in the array
// return the expected answer

string mostFrequentWord(string arr[], int n)
{
    map<string, int> mp;   // stores frequency of each character
    map<string, int> indi; // stores first occurrence of each character

    // count frequency of each word in arrayunordered_
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;

        if (indi.find(arr[i]) == indi.end()) // denoting first occurrence of string
            indi[arr[i]] = i;
    }

    int res = INT_MIN;
    string word = "";
    int index = -1;

    for (int i = 0; i < n; i++)
    {
        if (mp[arr[i]] > res)
        {
            res = mp[arr[i]]; // new maximum frequency
            index = indi[arr[i]];
            word = arr[i];
        }
        else if (mp[arr[i]] == res)
        {
            if (indi[arr[i]] > index) // for same frequency update if first occurrence is later
            {
                index = indi[arr[i]];
                word = arr[i];
            }
        }
    }

    return word;
}