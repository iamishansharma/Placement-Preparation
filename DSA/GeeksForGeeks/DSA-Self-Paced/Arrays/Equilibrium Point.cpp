// { Driver Code Starts
#include <iostream>
using namespace std;

// Position this line where user code will be pasted.

int equilibriumPoint(long long a[], int n);

int main() {

    long long t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        long long a[n];

        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }

        cout << equilibriumPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


// Function to find equilibrium point
// a: input array
// n: size of array
int equilibriumPoint(long long a[], int n) 
{
    if(n == 1)
        return 1;
    
    if(n == 2)
        return -1;
        
    for(int i=1; i<n; i++)
        a[i] = a[i-1] + a[i];
    
    // 1 4 9 11 13
    int left = 0;
    int right = 0;
    
    for(int i=1; i<=n-2; i++)
    {
        left = a[i-1];
        right = a[n-1] - a[i];
        
        if(left == right)
            return i+1;
    }
    return -1;
}