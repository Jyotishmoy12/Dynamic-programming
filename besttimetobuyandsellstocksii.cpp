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
