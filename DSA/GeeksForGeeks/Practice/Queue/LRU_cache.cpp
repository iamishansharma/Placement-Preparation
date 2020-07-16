// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

/*

The task is to design and implement methods of an LRU cache. The class has two methods get() and set() which are defined as follows.
get(x)   : Returns the value of the key x if the key exists in the cache otherwise returns -1.
set(x,y) : inserts the value if the key x is not already present. If the cache reaches its capacity it should invalidate the least recently used item before inserting the new item.
In the constructor of the class the size of the cache should be intitialized.

Input:

The first line of input contain an integer T denoting the number of test cases. 
Then T test case follow. Each test case contains 3 lines. 
The first line of input contains an integer N denoting the capacity of the 
cache and then in the next line is an integer Q denoting the number of queries 
Then Q queries follow. A Query can be of two types

1. SET x y : sets the value of the key x with value y
2. GET x : gets the key of x if present else returns -1.

Output:
For each test case, in a new line, output will be space separated values of the query.

Your Task:
This is a function problem. You only need to complete the provided functions.

Constraints:
1 <= T <= 100
1 <= N <= 1000
1 <= Q <= 100000
1 <= x, y <= 1000

Example:
Input:

2
2
2
SET 1 2 GET 1
2
7
SET 1 2 SET 2 3 SET 1 5 SET 4 5 SET 6 7 GET 4 GET 1

Output:
2
5 -1

Explanation: 

Test 

Case 1: Cache Size = 2

SET 1 2 GET 1

SET 1 2 : 1 -> 2
GET 1 : Print the value corresponding to Key 1, ie 2.

Test Case 2: Cache Size = 2

SET 1 2 SET 2 3 SET 1 5 SET 4 5 SET 6 7 GET 4 GET 1
SET 1 2 : 1 -> 2
SET 2 3 : 1 -> 2, 2 -> 3 (the most recently used one is kept at the rightmost position) 
SET 1 5 : 2 -> 3, 1 -> 5
SET 4 5 : 1 -> 5, 4 -> 5 (Cache size is 2, hence we delete the least recently used key-value pair)
SET 6 7 : 4 -> 5, 6 -> 7 
GET 4 : Prints 5
GET 1 : No key-value pair having key = 1. Hence prints -1.

*/

// design the class:

class LRUCache
{
private:

public:
    LRUCache(int cap)
    {
        // constructor for cache
    }
    
    static int get(int key)
    {
        // this function should return value corresponding to key
    }
    
    static void set(int key, int value)
    {
        // storing key, value pair
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends