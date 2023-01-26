#include <bits/stdc++.h> 
// int minimumElementsUtil(vector<int>& arr, int ind, int T, vector<vector<int>>& dp){

//     if(ind == 0){
//         if(T%arr[0] == 0) return T/arr[0];
//         else return 1e9;
//     }
    
//     if(dp[ind][T]!=-1)
//         return dp[ind][T];
        
//     int notTaken = 0 + minimumElementsUtil(arr,ind-1,T,dp);
    
//     int taken = 1e9;
//     if(arr[ind] <= T)
//         taken = 1 + minimumElementsUtil(arr,ind,T-arr[ind],dp);
        
//     return dp[ind][T] = min(notTaken,taken);
//}
int minimumElements(vector<int> &nums, int x)
{
   int n= nums.size();
    
    vector<vector<int>> dp(n,vector<int>(x+1,0));
    for(int T=0; T<=x; T++){
        if(T%nums[0]==0)
        dp[0][T]=T/nums[0];
        else dp[0][T]=1e9;
    }
    for(int ind=1; ind<n; ind++){
        for(int T=0;T<=x;T++){
            int notake=0+dp[ind-1][T];
            int take=1e9;
            if(nums[ind]<=T){
            take=1+dp[ind][T-nums[ind]];
            }
          dp[ind][T]=min(take, notake); 
        }
    }

    int ans =  dp[n-1][x];
    if(ans >= 1e9) return -1;
    return ans;
}
