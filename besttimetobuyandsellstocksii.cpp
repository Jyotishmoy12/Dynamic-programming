//MEMOIZATION
class Solution {
    private:
    int f(int ind, int buy, vector<int>&values, int n, vector<vector<int>>&dp){
    if(ind==n) return 0;
    if(dp[ind][buy]!=-1) return dp[ind][buy];
    long profit=0;
    if(buy){
       profit=max(-values[ind]+f(ind+1,0, values, n,dp),
       0+f(ind+1, 1, values, n, dp)); 
    }
    else{
        profit=max(values[ind]+f(ind+1, 1, values, n, dp), 0+f(ind+1, 0, values, n, dp));
    }
    return dp[ind][buy]=profit;
}
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
     vector<vector<int>>dp(n, vector<int>(2, -1));
  return f(0, 1, prices,n,dp);     
    }
};

//TABULATION
#include<vector>
long getMaximumProfit(long *values, int n)
{
 vector<vector<long>>dp(n+1, vector<long>(2, 0));
  dp[n][0]=dp[n][1]=0;
  for(int ind=n-1;ind>=0;ind--){
      for(int buy=0;buy<=1; buy++){
        long profit=0;
        if(buy){
       profit=max(-values[ind]+dp[ind+1][0],
       0+dp[ind+1][1]); 
    }
    else{
        profit=max(values[ind]+dp[ind+1][1], 0+dp[ind+1][0]);
    } 
    dp[ind][buy]=profit;  
      }
  }
  return dp[0][1];
}
