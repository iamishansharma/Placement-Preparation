#include <iostream>
#include <iomanip>
using namespace std;

int b[100000];
double p[100000];
int main() {
	// your code goes here
	
	ios::sync_with_stdio(false);
    cin.tie(0);
	
	int t;
	cin>>t;
	while(t--)
	{
	   
	    int n;
	    cin>>n;
	    
	    for(int i=0;i<n;i++)
	    cin>>b[i];
	     
	    for(int i=0;i<n;i++)
	    cin>>p[i];
	    
	    double ans=0;
	    for(int k=0;k<=30;k++)
	    {
	        double prob=0;
	        for(int i=0;i<n;i++)
	        {
	            if(b[i]&1<<k)
	            prob = prob*(1-p[i]) + (1-prob)*p[i];
	        }
	        ans+=prob*(1<<k);
	    }
	    cout<<setprecision(15)<<fixed<<ans<<endl;
	}
	return 0;
}
