#include <bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
int n,k;
int a[2011];
int IT[5011];
int LEAFOFFSET=2047;

void addValue(int val){
    int ind=val+LEAFOFFSET;
    IT[ind]++;
    ind/=2;
    while(ind>0){
        IT[ind]=IT[ind*2]+IT[2*ind+1];
        ind/=2;
    }
}
int kthFreq(int ver,int pos){
    if(ver>=LEAFOFFSET)
        return IT[ver];
    if(IT[2*ver+1]==0 || IT[2*ver]>=pos)
        return kthFreq(2*ver,pos);
    else
    {
        return kthFreq(2*ver+1,pos-IT[2*ver]);
    }
    
}
int intCeil(int a,int b){
    if(a%b==0)
        return a/b;
    else
    {
        return a/b+1;
    }
    
}
bool query(int ln){
    int replicas=intCeil(k,ln);
    int pos=intCeil(k,replicas);

    int freq=kthFreq(1,pos);

    return IT[freq+LEAFOFFSET]>0;
}
int main()
{
    int i,j;
    int ans=0;
    int t,test;
    scanf("%d",&t);
    for(test=1;test<=t;test++)
    {
        ans=0;
        scanf("%d %d",&n,&k);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(i=1;i<=n;i++)
        {
            memset(IT,0,sizeof(IT));
            for(j=i;j<=n;j++){
                addValue(a[j]);

                if(query(j-i+1))
                    ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}