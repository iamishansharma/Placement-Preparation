#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n, temp;
    cin>>n;
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < n; j++) 
        {
            cin>>temp;
            cout<<(i+j)%2<<" ";
        }
        cout<<"\n";
    }
    
	return 0;
}
