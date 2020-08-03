void buildSegTree(vector<int> &Tree,vector<int> &arr,int index,int start,int end)
{
    if(start==end)
    {
        Tree[index]=arr[start];
        return;
    }
    int mid=(start+end)/2;
    buildSegTree( Tree,arr,2*index+1,start,mid);
    buildSegTree( Tree,arr,2*index+2,mid+1,end);
    Tree[index]=Tree[2*index+1] + Tree[2*index+2] ; 
}
void update(vector<int> &Tree,vector<int> &arr,int index,int start,int end,int x,int val)
{
    if(start==end)
    {
        Tree[index]=val;
        arr[x]=val;
        return;
    }
    int mid=(start+end)/2;
    if(x<=mid)
    {
        update(Tree,arr,2*index+1,start,mid,x,val);
    }
    else
    {
        update(Tree,arr,2*index+2,mid+1,end,x,val);
    }
    Tree[index]=Tree[2*index+1] + Tree[2*index+2];
}
int query(vector<int> &Tree,vector<int> &arr,int index,int start,int end, int L ,int R)
{
    if(start>R or end<L)
    {
        return 0;
    }
    if(L<=start and end<=R)
    {   
        return Tree[index];
    }
    int mid=(start+end)/2;
    int q1=query(Tree,arr,2*index+1,start,mid,L,R);
    int q2=query(Tree,arr,2*index+2,mid+1,end,L,R);
    return q1+q2;
}
int index(vector<int> &Tree,vector<int> &arr,int K)
{
    int N=arr.size();
    int start=0;
    int end=N-1;
    int mid;
    while(start<end)
    {
        mid=(start+end)/2;
        int sum=query(Tree,arr,0,0,N-1,0,mid);
        if(K==sum)
        {
            start=mid+1;
        }
        else if(K>sum)
        {
            start=mid+1;
        }
        else
        {
            end=mid;
        }
    }
    return start;
}
vector<int> Solution::order(vector<int> &A, vector<int> &B) 
{
    int N=A.size();
    map<int,int> hash;
    for(int i=0;i<N;i++)
    {
        hash[A[i]]=B[i];
    }
    vector<int> pos(N,1);
    vector<int> ans(N,-1);
    vector<int> Tree(4*N,0);
    buildSegTree(Tree,pos,0,0,N-1);
    for(auto it:hash)
    {
        int ix=index(Tree,pos,it.second);
        ans[ix]=it.first;
        update(Tree,pos,0,0,N-1,ix,0);
    }
    return ans;
}