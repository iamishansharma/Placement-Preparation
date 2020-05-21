#include <bits/stdc++.h>
using namespace std;
bool can[26];
int n, m, k, q, res = 0;
char key[31][31];
char text[1000000];
vector<pair<int, int>> posKey[26], shift;

int dist(int i, int j, int shr, int shc)
{
	return (i - shr)*(i - shr) + (j - shc)*(j - shc);
}

bool check(int i, int j)
{
	for (int w = 0;w < shift.size();w++)
	{
		int dis = dist(i, j, shift[w].first, shift[w].second);
		if (dis <= k*k)
			return true;
	}
	return false;
}


int main()

{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0;i < n; i++)              // keyboard keys
		scanf("%s", key[i]);



	for (int i = 0;i<n;i++) 
		for (int j = 0;j < m;j++)
		{
			if (key[i][j] == 'S')
				shift.push_back(make_pair(i, j));                          // position of each key
			else
				posKey[key[i][j] - 'a'].push_back(make_pair(i, j));
		}




	for (int i = 0;i<26; i++)
		for (int j = 0;j <posKey[i].size() && !can[i]; j++)
		{                                                                         //check of each key if can press on it with one hand
			can[i] = can[i] | check(posKey[i][j].first, posKey[i][j].second);
		}



	scanf("%d%s", &q, text);
	for (int i = 0;i < q;i++)
	{
		if (islower(text[i]))
		{
			if (posKey[text[i] - 'a'].empty())
			{
				res = -1;
				break;
			}
		}
		else
		{
			text[i] = tolower(text[i]);

			if (shift.empty() || posKey[text[i] - 'a'].empty())
			{
				res = -1;
				break;

			}

			if (!can[text[i] - 'a'])
				++res;
		}
	}
	printf("%d", res);

	return 0;
}