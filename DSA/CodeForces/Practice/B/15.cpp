#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

void solve()
{
	int n=0;
	cin>>n;

	string main = "ROYGBIV";
	string sec[7] = {"", "G", "GB", "YGB", "YGBI", "OYGBI", "OYGBIV"};

	string answer;

	for(int i=0; i< (n/7); i++)
		answer = answer + main;

	int rem = n%7;

	answer += sec[rem];

	cout<<answer<<endl;
}

int main()
{
	fastIO;

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout); 
	#endif
	
	solve();
}