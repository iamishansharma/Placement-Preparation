// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    bool isEndOfWord;
    int count1;
    map<char, Node *> mp;
};

Node *newNode()
{
    Node *temp = new Node();
    temp->isEndOfWord = false;
    // int count1 = 0;
    return temp;
}

void check(string *arr, int n);

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
        {
            string s;
            cin >> s;
            arr[i] = s;
        }
        check(arr, n);
    }
    return 0;
}
// } Driver Code Ends

//User function template for C++

// arr : array of strings
// n : count of the number of strings in the array
unordered_map<string, int> mp;
typedef struct TrieNode TrieNode;

struct TrieNode
{
    TrieNode *child[26];
    int count;
    bool suffix;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
            child[i] = NULL;

        count = 0;
        suffix = false;
    }
};

void insert(TrieNode *root, string k)
{
    TrieNode *curr = root;

    for (int i = 0; i < k.length(); i++)
    {
        int index = k[i] - 'a';

        if (curr->child[index] == NULL)
            curr->child[index] = new TrieNode();

        curr = curr->child[index];
        curr->count++;
    }
}

void search(TrieNode *root, string k)
{
    TrieNode *curr = root;
    mp[k] += 1;

    for (int i = 0; i < k.length(); i++)
    {
        int index = k[i] - 'a';

        if (i == 0)
        {
            if (curr->child[index]->suffix == false)
            {
                curr->child[index]->suffix = true;
                cout << k[0] << endl;
                return;
            }
            curr = curr->child[index];
        }
        else
        {
            if (curr->child[index]->count == 1)
            {
                cout << k.substr(0, i + 1) << endl;
                return;
            }
            curr = curr->child[index];
        }
    }

    if (mp[k] == 1)
        cout << k << endl;
    else
        cout << k << " " << mp[k] << endl;
}

void check(string *arr, int n)
{
    TrieNode *root = new TrieNode();

    for (int i = 0; i < n; i++)
    {
        insert(root, arr[i]);
        search(root, arr[i]);
    }
}
