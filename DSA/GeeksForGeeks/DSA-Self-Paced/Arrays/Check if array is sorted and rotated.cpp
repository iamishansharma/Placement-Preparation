// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// arr: input array
// num: length of array
// This function returns true or false
bool issortedas(int arr[],int num)
{
    
    for(int i=0;i<num-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            return false;
        }
    }
    
    return true;
}

bool issorteddesc(int arr[],int num)
{
    
    for(int i=0;i<num-1;i++)
    {
        if(arr[i]<arr[i+1])
        {
            return false;
        }
    }
    
    return true;
}


bool checkRotatedAndSorted(int arr1[], int num){
    
    int arr[num];
    
    for(int i=0;i<num;i++)
    {
        arr[i] = arr1[i];
    }
    
    if(num==1)
    {
        return true;
    }
    else
    {
    int largest = arr[0];
    int largesti = 0;
    for(int i=1;i<num;i++)
    {
        if(largest<=arr[i])
        {
            largest = arr[i];
            largesti = i;
        }
    }
    
    rotate(arr,arr+largesti+1,arr+num);
    
    int flag = 1;
    
    for(int i=0;i<num;i++)
    {
        if(arr[i]!=arr1[i])
        {
            flag=0;
            break;
        }
    }
    
    if(issortedas(arr,num) && (flag==0))
    {
        return true;
    }
    
    rotate(arr,arr+num-1,arr+num);
    flag=1;
    for(int i=0;i<num;i++)
    {
        if(arr[i]!=arr1[i])
        {
            flag=0;
            break;
        }
    }
    
    if(issorteddesc(arr,num) && (flag==0))
    {
        return true;
    }
    
    return false;
    }
    
}

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--){
	    int num;
        cin>>num;
        int arr[num];
        for(int i = 0; i<num; ++i)
            cin>>arr[i];
        
        bool flag = false;
        
        flag = checkRotatedAndSorted(arr, num);
        
        if(!flag){
            cout << "No"<<endl;
        }
        else
        cout << "Yes"<<endl;
    
	}
	
	return 0;
}  // } Driver Code Ends