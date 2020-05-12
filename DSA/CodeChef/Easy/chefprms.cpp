#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
using namespace std;

vector<int> v;
bool sp[201];

void isSemiPrime()
{
    for(int i=6; i<=200; i++)
    {
        int n=i;
        int count=0;
        bool flag=true;
        for(int j=2; j<=sqrt(n)&&count<2; j++)
        {
            if(n % j == 0)
            {
                count++;
                n/=j;
                if(n % j == 0)
                {
                    flag = false;
                    break;
                }
            }
        }
        if(n > 1)
        {
            sp[i]=false;
            count++;
        }
        if(count==2 && flag==true)
        {
            sp[i]=true;
            v.push_back(i);
        }
        else
        {
            sp[i]=false;
        }
    }
}

bool checkSumOfTwoSemiPrime(int n)
{
    int i=0;
    while(v[i]<=n/2)
    {
        if(sp[n-v[i]])
        {
            return true;
        }
        else
        {
            i++;
        }
    }
    return false;
}

void solve()
{
	int n;
	cin>>n;

	isSemiPrime();

    if(checkSumOfTwoSemiPrime(n))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

int main()
{
	fastIO;

	/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif*/
	
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
	return 0;
}