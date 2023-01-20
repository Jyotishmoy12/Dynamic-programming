//MEMOIZATION

#include <bits/stdc++.h> 
int f(int ind, int W,vector<int>&wt, vector<int>&val,vector<vector<int>>&dp){
    if(ind==0){
        if(wt[0]<=W) return val[0];
        else return 0;
    }
    if(dp[ind][W]!=-1) return dp[ind][W];
    int notsteal=0+f(ind-1, W, wt, val,dp);
    int steal=INT_MIN;
    if(wt[ind]<=W)
        steal=val[ind]+f(ind-1, W-wt[ind], wt, val,dp);
    return dp[ind][W]= max(steal, notsteal);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    vector<vector<int>>dp(n, vector<int>(maxWeight+1, -1));
    return f(n-1, maxWeight, weight, value, dp);
}
