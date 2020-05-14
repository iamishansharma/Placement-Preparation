#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

void solve()
{
	int i,j,n,m,ctr=1,flag=0;
	std::cin >> n>>m;
	for(i=3;i<=m+n;i+=2)
	{
		 flag=0;
		 for(j=3;j<sqrt(i)+1;j++)
		  {
			  if(i%j==0)
			  {
				  flag=1;
				  break;
			  }
			  
		  }
		  if(flag==0)
		  ctr++;
	}
	std::cout << ctr<< std::endl;
}

int main()
{
	fastIO;

	/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif*/
	
	solve();
	return 0;
}