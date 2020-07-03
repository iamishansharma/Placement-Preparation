#include <bits/stdc++.h>
using namespace std;

int cutRod(int remLen, vector<int> &dp, int x, int y, int z) 
{
    if (remLen == 0) 
        return 0;
        
    if (remLen < 0) 
        return INT_MIN;
        
    if (dp[remLen] == -1) 
    {
        if (remLen - x >= 0) 
            dp[remLen] = 1 + cutRod(remLen-x, dp, x, y, z);
            
        if (remLen - y >= 0) 
            dp[remLen] = max(dp[remLen], 1+cutRod(remLen-y, dp, x, y, z));
            
        if (remLen - z >= 0) 
            dp[remLen] = max(dp[remLen], 1+cutRod(remLen-z, dp, x, y, z));
            
        if (dp[remLen] == -1) 
            dp[remLen] = INT_MIN;
    }
    return dp[remLen]; 
}

int main() 
{
	int t;
	cin >> t;
	
	while(t--) 
	{
	    int n, x, y, z;
	    cin >> n >> x >> y >> z;
	    
	    vector<int> dp(n+1);
	    
	    for (int i=0; i < n+1; i++) 
	        dp[i] = -1;
	        
	    cout << cutRod(n, dp, x, y, z) << "\n";
	}
	return 0;
}