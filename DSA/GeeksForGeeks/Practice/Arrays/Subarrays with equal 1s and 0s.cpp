// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

long long int countSubarrWithEqualZeroAndOne(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	cout<< countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}
// } Driver Code Ends




// arr[] : the input array
// N : size of the input array

// return the number of subarrays with equal 0s and 1s
#define ll long long int
long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
{
    for(int i=0; i<n; i++)
        arr[i] = arr[i] == 0 ? -1 : 1;
    
    ll prefix[n];
    
    prefix[0] = arr[0];
    
    for(int i=1; i<n; i++)
        prefix[i] = prefix[i-1] + arr[i];
        
    ll count = 0;
    
    unordered_map<int,int> mp;
    
    for(int i=0; i<n; i++)
    {
        if(mp[prefix[i]] > 0)
            count += mp[prefix[i]];
        
        if(prefix[i] == 0)
            count++;
            
        mp[prefix[i]]++;
    }
    
    return count;
}