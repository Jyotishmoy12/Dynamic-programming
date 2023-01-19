//memoization and tabulation both

#include <bits/stdc++.h>
// int f(int ind, int sum, vector<int> &num, vector<vector<int>>&dp){
//    if(sum==0) return 1;
//     if(ind==0) return (num[0]==sum);
//     if(dp[ind][sum]!=-1) return dp[ind][sum];
//     int notpick=f(ind-1, sum, num, dp);
//     int pick=0;
//     if(num[ind]<=sum) 
//      pick=f(ind-1, sum-num[ind], num, dp);
//     return dp[ind][sum]=pick+notpick;
// }
int findWays(vector<int> &num, int tar)
{   int n=num.size();
   vector<vector<int>>dp(n, vector<int>(tar+1, 0));
 for(int i=0;i<n;i++) dp[i][0]=1;
 if(num[0]<=tar) dp[0][num[0]]=1;
for(int i=1;i<n;i++){
    for(int sum=0;sum<=tar; sum++){
      int notpick=dp[i-1][sum];
      int pick=0;
     if(num[i]<=sum) 
     pick=dp[i-1][sum-num[i]];
     dp[i][sum]=pick+notpick; 
    }
} 
    return dp[n-1][tar];
}
