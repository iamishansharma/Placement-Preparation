#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		vector<int> keys;
		int temp;
		for(int i=0; i<n; i++)
		{
			cin>>temp;
			keys.push_back(temp);
		}

		vector<int> inf(keys.size());

		for(int i=0; i<inf.size(); i++)
			inf[i] = 1;

		for(int i=0; i<keys.size(); i++)
		{
			// RIGHT
			for(int j=i+1; j<keys.size(); j++)
			{
				if(abs(keys[j]-keys[j-1]) == 2 || abs(keys[j]-keys[j-1]) == 1 || abs(keys[j]-keys[j-1]) == 0)
				{
					
					inf[i]++;
				}
				else
				{
					
					break;
				}
			}

			// LEFT
			for(int j=i-1; j>=0; j--)
			{

				if(abs(keys[j]-keys[j+1]) == 2 || abs(keys[j]-keys[j+1]) == 1 || abs(keys[j]-keys[j+1]) == 0)
				{
					
					inf[i]++;
				}
				else
				{
					
					break;
				}
			}
		}
		printf("%d %d\n", *min_element(inf.begin(),inf.end()), *max_element(inf.begin(),inf.end()));
	}
	return 0;
}