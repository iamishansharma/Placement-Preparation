#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		int yy=0;
		int mm=0;
		int dd=0;
		char dummy;
		int count = 0;

		cin>>yy>>dummy>>mm>>dummy>>dd;

		if(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12)
		{
	        if(dd%2==0) 
	        	count=((30-dd)/2)+1;
	        else 
	        	count=(31-dd)/2+1;
	    }
	    else if(mm==4|| mm==6||mm==9||mm==11)
	    {
	        if(dd%2==0) 
	        	count=((30-dd)/2)+1+15;
	        else 
	        	count=((31-dd)/2)+16;
	    }
	    else
	    {
	        if((yy%4==0 && yy%100!=0) || (yy%400==0 && yy%100==0))
	        {
	            if(dd%2==0) 
	            	count=((28-dd)/2)+1;
	            else 
	            	count=((29-dd)/2)+1;
	        }
	        else {
	            if(dd%2==0) 
	            	count=((28-dd)/2)+16;
	            else 
	            	count=((29-dd)/2)+16;
	        }
	    }
	    cout<<count<<"\n";
	}
	return 0;
}