#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

typedef long long LL;

const int N = 100001;
const int MOD = 1000000007;

int f[N];

LL powr(LL x, LL y) 
{
	if(y == 0) 
		return 1;

	LL tmp = powr(x, y / 2);
	LL z = ((tmp % MOD) * (tmp % MOD)) % MOD;

	if(y & 1) 
		z = ((z % MOD) * (x % MOD)) % MOD;

	return z;
}

void pre() 
{
	f[1] = 1LL;
	for(int i = 2 ; i < N ; i++) 
	{
		f[i] = (f[i - 1] * ((powr(2, i - 1) - 1 + MOD) % MOD)) % MOD;
	}
}

int main() 
{
	fastIO;
	pre();
	int T, N; scanf("%d", &T);
	while(T--) 
	{
		scanf("%d", &N); printf("%d\n", f[N]);
	}
}