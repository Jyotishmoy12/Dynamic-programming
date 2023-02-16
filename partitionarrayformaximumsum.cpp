class Solution {
    int f(int ind, vector<int>&nums, int k, vector<int>&dp){
        int n=nums.size();
        if(dp[ind]!=-1) return dp[ind];
        if(ind==n) return 0;
        int len=0;
        int maxi=INT_MIN;
        int maxAns=INT_MIN;
        for(int j=ind;j<min(ind+k,n);j++){
            len++;
            maxi=max(maxi, nums[j]);
            int sum=len*maxi+f(j+1, nums, k,dp);
            maxAns= max(maxAns, sum);
        }
        return dp[ind] = maxAns;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
     int n=arr.size();
     vector<int>dp(n+1, -1);
     return f(0, arr, k, dp);   
    }
};


class Solution {
  
public:
    int maxSumAfterPartitioning(vector<int>& nums, int k) {
     int n=nums.size();
     vector<int>dp(n+1, 0);
     dp[n]=0;
     for(int ind=n-1; ind>=0;ind--){
        int len=0;
        int maxi=INT_MIN;
        int maxAns=INT_MIN;
        for(int j=ind;j<min(ind+k,n);j++){
            len++;
            maxi=max(maxi, nums[j]);
            int sum=len*maxi+dp[j+1]; 
            maxAns= max(maxAns, sum);
        }
       dp[ind] = maxAns; 
     }
     
     return dp[0];   
    }
};
