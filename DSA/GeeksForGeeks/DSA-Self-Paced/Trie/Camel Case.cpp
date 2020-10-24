// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// Alphabet size (# of upper-Case characters)
#define ALPHABET_SIZE 26

void findAllWords(vector<string>, string);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int now;
        cin >> now;
        vector<string> dict(now);
        for (int i = 0; i < now; i++)
            cin >> dict[i];

        string pattern;
        cin >> pattern;

        findAllWords(dict, pattern);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

//User function template for C++

// dict : given set of strings
// pattern : given pattern
void findAllWords(vector<string> dict, string pattern)
{
    multimap<string, string> mp;
    string abr;

    bool flag;

    for (int i = 0; i < dict.size(); i++)
    {
        string key = dict[i];
        abr.clear();
        flag = false;

        for (int j = 0; j < key.size(); j++)
        {
            if (key[j] - 'A' < 26)
                abr = abr + key[j];

            if (abr == pattern)
            {
                flag = true;
            }
        }

        if (flag)
        {
            mp.insert({abr, key});
        }
    }

    if (mp.size() == 0)
    {
        cout << "No match found";
        return;
    }

    multiset<string> res;
    abr.clear();

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (abr.empty())
        {
            abr = it->first;
        }

        if (abr == it->first)
        {
            res.insert(it->second);
        }
        else
        {
            for (string x : res)
                cout << x << " ";

            res.clear();
            res.insert(it->second);
            abr = it->first;
        }
    }

    if (res.size() != 0)
        for (string x : res)
            cout << x << " ";
}