#include <bits/stdc++.h>
using namespace std;

int vBinarySearch(vector<int> wormholes, int size, int key)
{
	int low = 0;
	int high = size-1;
	int mid,closestWormHole=-1;

	while (low <= high)
	{
		mid = (low + high)/2;

		if (wormholes[mid] == key)
			break;
		else if (wormholes[mid] > key)
			high = mid-1;
		else
		{
			closestWormHole = mid;
			low = mid + 1;
		}
	}

	if (low > high)
		return closestWormHole;
	else
		return mid;
}

int wBinarySearch(vector<int> wormholes, int size, int key)
{
	int low = 0;
	int high = size-1;
	int mid,closestWormHole=-1;

	while (low <= high)
	{
		mid = (low + high)/2;

		if (wormholes[mid] == key)
			break;
		else if (wormholes[mid] > key)
		{
			closestWormHole = mid;
			high = mid-1;
		}
		else
			low = mid + 1;
	}

	if (low > high)
		return closestWormHole;
	else
		return mid;
}

int main()
{
	int n,x,y;
	cin>>n>>x>>y;

	int contests[n][2];

	for(int i=0; i<n; i++)
		cin>>contests[i][0]>>contests[i][1];

	vector<int> v(x);

	for(int i=0; i<x; i++)
	{
		cin>>v[i];
	}

	vector<int> w(y);

	for(int i=0; i<y; i++)
		cin>>w[i];

	sort(v.begin(),v.end());
	sort(w.begin(),w.end());

	int minDuration = w[y-1] - v[0] + 1; // Maximum wormhole travel possible;

	int temp = 0;

	for(int i=0; i<n; i++)
	{
		if(contests[i][1] - contests[i][0] + 1 >= minDuration)
			continue;

		int start = vBinarySearch(v,x,contests[i][0]);
		int end = wBinarySearch(w,y,contests[i][1]);

		if(start == -1 || end == -1)
			continue;

		temp = w[end] - v[start] + 1;

		if(temp < minDuration)
			minDuration = temp;
	}

	cout << minDuration << endl;
}
