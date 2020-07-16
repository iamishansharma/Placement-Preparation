#include<iostream>
#include<algorithm>
using namespace std;

void maxCoins(int a[],int n,int k)
{
    int i=1,c=0,s=0,j=0;
    sort(a,a+n);
    while(s<=k)
    {
        if(i!=a[j])
        {
            c++;
            i++;
            s = s + i;
        }
        else if(i==a[j])
        {
            i++;
            j++;
        }
    }
    cout<<c<<endl;
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    int a[n],i;
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    maxCoins(a,n,k);
	}
	return 0;
}