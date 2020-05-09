#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int ans(int neuron[][2],int n)
{   if(n==1)
    {   if(neuron[0][0]==1&&neuron[0][1]==1)
	        return 1;
        else if(neuron[0][0]==1&&neuron[0][1]==0)
	        return 0;
        else if(neuron[0][0]==0&&neuron[0][1]==1)
            return 2;
        else
            return 3;
    }
    if(neuron[n-1][0]==1&&neuron[n-1][1]==1)
	        return 1;
     else if(neuron[n-1][0]==1&&neuron[n-1][1]==0)
	        return 0;
	else
	{
	    int a= ans(neuron,n-1);   
	    if(a==1&&neuron[n-1][1]==1 )
	        return 1;
	    else if(a==1&&neuron[n-1][1]==0)
	        return 0;
	    else if(a==0&&neuron[n-1][1]==0)
            return 1;
        else if(a==0&&neuron[n-1][1]==1)
            return 0;
        else if(a==2&&neuron[n-1][1]==0)
            return 3;
        else if(a==2&&neuron[n-1][1]==1)
            return 2;
        else if(a==3&&neuron[n-1][1]==0)
            return 2;
        else if(a==3&&neuron[n-1][1]==1)
            return 3;
	    
	}
    
}
long long countOdd(long long R, long long L){  
  
    long long N = (R - L) / 2; 
    if (R % 2 != 0 || L % 2 != 0)  
        N += 1; 
  
    return N; 
} 
int main() {
	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int t,n,x,y;
	long long minx,maxx;
	cin>>t;
	while(t--)
	{
	    cin>>n>>minx>>maxx;
	    int neuron[n][2];
	    long long out=maxx-minx+1;
	    long long ecount=0;
	    long long ocount=0;
	    for(int i=0;i<n;i++)
	    {   
	        cin>>x>>y;
	        neuron[i][0]=(x%2==0)?(1):(0);
	        neuron[i][1]=(y%2==0)?(1):(0);   
	       //cout<<neuron[i][0]<<" "<<neuron[i][1]<<"\n";
	    }
	    int a=ans(neuron,n);
	    //cout<<a<<" ";
	    if(a==1)
	        ecount=out;
	    else if (a==0)
	        ocount=out;
	    else if (a==2)
	       {    //cout<<a<<" ";
	           ocount = countOdd(maxx,minx);  
                ecount = out - ocount;  
	       }
	   else
	      {  //cout<<a<<" ";
	           ecount = countOdd(maxx,minx);  
                ocount = out - ecount;  
	       }
	   cout<<ecount<<" "<<ocount<<"\n";
	}
	
	return 0;
}
