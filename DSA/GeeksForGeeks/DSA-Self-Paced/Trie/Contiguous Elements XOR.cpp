// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;
#define INT_SIZE 32

int maxSubarrayXOR(int *, int);

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << maxSubarrayXOR(arr, n) << endl;
    }

    return 0;
} // } Driver Code Ends

//User function template for C++

// arr : given array
// n : size of the given array
class Trie
{
public:
    int value = 0;
    Trie *bits[2];
};

void InsertInTrie(Trie *root, int pre_xor)
{
    Trie *temp = root;

    for (int i = 31; i >= 0; i--)
    {
        int bit = (pre_xor >> i) & 1;

        if (temp->bits[bit] == NULL)
            temp->bits[bit] = new Trie();

        temp = temp->bits[bit];
    }
    temp->value = pre_xor;
}

int CurrentXOR(Trie *root, int pre_xor)
{
    Trie *temp = root;

    for (int i = 31; i >= 0; i--)
    {
        int bit = (pre_xor >> i) & 1;

        if (temp->bits[1 - bit] != NULL)
            temp = temp->bits[1 - bit];
        else if (temp->bits[bit] != NULL)
            temp = temp->bits[bit];
    }

    return pre_xor ^ (temp->value);
}

int maxSubarrayXOR(int arr[], int n)
{
    Trie *root = new Trie();
    InsertInTrie(root, 0);

    int pre_xor = 0;
    int max_val = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        pre_xor = pre_xor ^ arr[i];

        InsertInTrie(root, pre_xor);

        max_val = max(max_val, CurrentXOR(root, pre_xor));
    }

    return max_val;
}