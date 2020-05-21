#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
typedef long long int ll;
using namespace std;

void solve()
{
	long n, m, k, t; 
	scanf("%ld %ld %ld %ld\n", &n, &m, &k, &t);
    std::vector<long> wasteCells(k, 0);

    for(long p = 0; p < k; p++)
    {
        long row, col; 
        scanf("%ld %ld\n", &row, &col);

        wasteCells[p] = m * (row - 1) + (col - 1);
    }

    sort(wasteCells.begin(), wasteCells.end());

    for(long p = 0; p < t; p++)
    {
        long row, col; 
        scanf("%ld %ld\n", &row, &col);
        long cellNumber = m * (row - 1) + (col - 1);
        long index = 0, wasteNumber = 0;
        
        while(index < k)
        {
            if(wasteCells[index] < cellNumber)
            	++index;
            else if(wasteCells[index] >= cellNumber)
            	break;
        }

        if(wasteCells[index] == cellNumber)
        	puts("Waste");
        else
        {
            long cropNumber = cellNumber - index;

            if(cropNumber % 3 == 0)
            	{puts("Carrots");}
            else if(cropNumber % 3 == 1){
            	puts("Kiwis");}
            else if(cropNumber % 3 == 2)
            	{puts("Grapes");}
        }
    }
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