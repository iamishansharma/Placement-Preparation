#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define ll long long

int T;
int N, K, Q, L, R;
char S[110000];
 
ll toL[110000], toR[110000], sum[110000];
int cnt[2];

int main(){
  int i, j, k;
  ll res;

  scanf("%d",&T);
  while(T--){
    scanf("%d%d%d%s",&N,&K,&Q,S);
    rep(i,N) S[i] -= '0';

    cnt[0] = cnt[1] = 0;
    j = 0;
    rep(i,N){
      while(j < N && cnt[S[j]]+1 <= K) cnt[S[j++]]++;
      toL[i] = j-1;
      cnt[S[i]]--;
    }

    cnt[0] = cnt[1] = 0;
    j = N-1;
    for(i=N-1;i>=0;i--){
      while(j >= 0 && cnt[S[j]]+1 <= K) cnt[S[j--]]++;
      toR[i] = j+1;
      cnt[S[i]]--;
    }

    sum[0] = 0;
    rep(i,N) sum[i+1] = sum[i] + toL[i];

    while(Q--){
      scanf("%d%d",&L,&R);
      L--; R--;

      k = toR[R] - 1;
      if(L <= k){
        res = sum[k+1] - sum[L] + (ll)(R - k) * R;
        res -= (ll)(L+R-2) * (R-L+1) / 2;
      } else {
        res = (ll)(R-L+2) * (R-L+1) / 2;
      }

      printf("%lld\n", res);
    }
  }

  return 0;
}