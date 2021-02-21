#include<stdio.h>

int main(){
  int modd = 1000000;
  int n, y, tests;
  int dp[1000000+1] ={[0 ... 1000000] = 0};
  int is_prime[1000000+1] ={[0 ... 1000000] = 1};
  is_prime[0] = 0;
  is_prime[1] = 0;
  for (int i = 2; i*i <= modd; i++) {
      if (is_prime[i] == 1) {
          for (int j = i*i; j <= modd; j += i)
              is_prime[j] = 0;
      }
  }
  dp[0] = dp[1] = 0;
  for(int i = 2; i<=modd; i++){
    dp[i] = dp[i-1];
    if(is_prime[ i ] == 1){
      dp[i]++;
    }
  }
  scanf("%d", &tests);
  while(tests-- > 0){
    scanf("%d", &n);
    scanf("%d", &y);
    /* printf("%d\n", dp[n]); */
    if( dp[n] <= y ) printf("Chef\n");
    // else cout << "Divyam\n";
    else printf("Divyam\n");
  }
  return 0;
}
