#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

void solve()
{
	int n=0;
	cin>>n;

	for(int l=0; l<n; l++)
	{
		int i=0,j=0;
		cin>>i>>j;

		/*int path = 0;

		vector<int> p1;
		vector<int> p2;

		int num1 = i;

		while(num1>0)
		{
			p1.push_back(num1);

			if(num1 % 2 == 0)
				num1 = num1/2;
			else
				num1 = (num1 - 1)/2;
		}

		int num2 = j;

		while(num2>0)
		{
			p2.push_back(num2);

			if(num2 % 2 == 0)
				num2 = num2/2;
			else
				num2 = (num2 - 1)/2;
		}

		for (std::vector<int>::iterator i = p1.begin(); i != p1.end(); ++i)
		{
			cout<<*i<<" ";
		}
		cout<<endl;

		for (std::vector<int>::iterator i = p2.begin(); i != p2.end(); ++i)
		{
			cout<<*i<<" ";
		}
		cout<<endl;

		int index1=0, index2=0;

		int flag = 0;

		for(vector<int>::iterator i1 = p1.begin(); i1 != p1.end(); ++i1)
		{
			index1++;
			index2=0;

			for(vector<int>::iterator i2 = p2.begin(); i2 != p2.end(); ++i2)
			{
				//cout<<"Index1: "<<index1<<" Index2: "<<index2<<" Ele1: "<<*i1<<" Ele2: "<<*i2<<endl;
				index2++;
				if(*i1 == *i2)
				{
					path = (index1-1) + (index2-1);
					flag = 1;
					break;
				}
			}
			if(flag)
				break;
		}

		*/

		int path = 0;

		while(i!=j)
		{
			if(i>j)
				i = i>>1;
			else
				j = j>>1;
			path++;
		}

		cout<<path<<endl;
	}
}

int main()
{
	fastIO;
	solve();
	return 0;
}