#include<stdio.h>

int main(){
  int mod = 1000000007;
  int n;
  scanf("%d", &n);
  int dp[n+1];
  dp[0] = dp[1] = 1;
  for(int i=2; i<=n; i++){
    dp[i]= 0;
  }
  for(int i=2; i<=n; i++){
    for(int j=1; j<=6; j++){
      if (j>i)
        break;
      dp[i] = ((dp[i]%mod) + dp[i-j]%mod)%mod;
    }
  }
  printf("%d",dp[n]);
}
