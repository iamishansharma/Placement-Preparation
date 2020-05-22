#include <bits/stdc++.h>
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int
using namespace std;

typedef pair <double, double> dd;
typedef pair <double, int> di;

const int Maxn = 100005;
const double Inf = 10e30;

int t;
int n;
dd A[Maxn];
set <di> S;
double res;

double Dist(int a, int b)
{
	return sqrt((A[a].first - A[b].first) * (A[a].first - A[b].first) + (A[a].second - A[b].second) * (A[a].second - A[b].second));
}

int main()
{
	fastIO;

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout); 
	#endif
	
	int t=0;
	cin>>t;

	for(int tc=1; tc <= t; tc++)
	{
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
			scanf("%lf %lf", &A[i].first, &A[i].second);

		sort(A, A + n);

		S.clear();

		res = Inf;

		int l = 0;

		for (int i = 0; i < n; i++) 
		{
			while (l < i && A[i].first - A[l].first >= res) 
			{
				S.erase(di(A[l].second, l)); 
				l++; 
			}
			set <di>::iterator lef = S.lower_bound(di(A[i].second - res, 0)), rig = S.upper_bound(di(A[i].second + res, n));

			for (set <di>::iterator it1 = lef; it1 != rig; it1++) 
			{
				set <di>::iterator it2 = it1;
				
				for (it2++; it2 != rig; it2++)
					res = min(res, Dist(i, it1->second) + Dist(i, it2->second) + Dist(it1->second, it2->second));
			}
			S.insert(di(A[i].second, i));
		}
		printf("Case %d: %.10lf\n", tc, res);
	}
	return 0;
}