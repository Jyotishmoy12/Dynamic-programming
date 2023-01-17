class Solution {
public:
    int n;
    
    int solve(string &s, int curr_index, int prev_val, vector<vector<int>>& dp) {
        if(curr_index >= n)
            return 0;
        
        if(dp[curr_index][prev_val] != -1)
            return dp[curr_index][prev_val];
        
        int flip    = INT_MAX;
        int no_flip = INT_MAX;

        if(s[curr_index] == '0') {
            
            if(prev_val == 1) {
                flip = 1 + solve(s, curr_index+1, 1, dp);
            } else {
                flip = 1 + solve(s, curr_index+1, 1, dp);
                no_flip = solve(s, curr_index+1, 0, dp);
            }
        }

        else if(s[curr_index] == '1')
        {
            if(prev_val == 1) {
                no_flip = solve(s, curr_index+1, 1, dp);
            } else {
                flip    = 1 + solve(s, curr_index+1, 0, dp);
                no_flip = solve(s, curr_index+1, 1, dp);
            }
        }

        return dp[curr_index][prev_val] =  min(flip, no_flip);
    }
    
    int minFlipsMonoIncr(string s) {
        n = s.length();
        
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        
        return solve(s, 0, 0, dp);
    }
};
