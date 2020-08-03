// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 501

int getId(int M[MAX][MAX],int n);

int main()
{
    int T;
    cin>>T;
    int M[MAX][MAX];
    while(T--)
    {
        int N;
        cin>>N;
        memset(M,0,sizeof M);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<getId(M,N)<<endl;

    }
}

// } Driver Code Ends


// The task is to complete this function

// M[][]: input matrix
// n: size of matrix (n*n)
int getId(int M[MAX][MAX], int n)
{
    vector<int> k(n);
    
    int flag1 = 0;
    int celeb = -1;
    
    for(int i=0; i<n; i++)
    {
        int sum = 0;
        
        for(int j=0; j<n; j++)
            sum += M[j][i];
        
        if(sum == n-1)
        {
            flag1 = 1;
            celeb = i;
            break;
        }
    }
    
    if(flag1 == 0)
        return -1;
    else
    {
        int flag2 = 0;
        
        for(int i=0; i<n; i++)
        {
            if(M[celeb][i] == 1)
            {
                flag2 = 1;
                break;
            }
        }
        
        if(flag2 == 1)
            return -1;
        else
            return celeb;
    }
}

/*

// Using stack

int getId(int M[MAX][MAX], int n)
{
    stack<int> s;
    
    for(int i=n-1; i>=0; i--)
        s.push(i);
        
    int size = n;
    
    while(size > 1)
    {
        int i = s.top();
        s.pop();
        int j = s.top();
        s.pop();
        
        if(M[i][j] == 1)
            s.push(j);
        else
            s.push(i);
            
        size--;
    }
    
    int celeb = s.top();
    
    int sum = 0;
    
    for(int i=0; i<n; i++)
        sum += M[i][celeb];
    
    if(sum != n-1)
        return -1;
    else
    {
        int flag = 0;
        
        for(int i=0; i<n; i++)
        {
            if(M[celeb][i] != 0)
            {
                flag = 1;
                break;
            }
        }
        
        if(flag == 1)
            return -1;
        else
            return celeb;
    }
}*/