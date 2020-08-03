// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> sortByFreq(int arr[],int n);

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    vector<int> v;
	    v = sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}

// } Driver Code Ends


//Complete this function
//Return the sorted array
bool comp(pair<int,int> p1, pair<int,int> p2)
{
    return p1.second == p2.second ? p1.first < p2.first : p1.second > p2.second;
}

vector<int> sortByFreq(int arr[],int n)
{
    unordered_map<int, int> ump;
    
    for(int i=0;i<n;i++)
        ump[arr[i]]++;
        
    vector<pair<int,int>> vec(ump.begin(),ump.end());
    
    sort(vec.begin(),vec.end(), comp);
    
    vector<int> ans;
    
    for(auto it = vec.begin(); it != vec.end(); ++it)
        while(it->second--)
            ans.push_back(it->first);
    
    return ans;
}