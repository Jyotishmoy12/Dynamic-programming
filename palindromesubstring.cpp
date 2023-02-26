class Solution {
public:
    int count = 0;
    
    // Finds whether there exists any pailndrome strings between the stated limit i.e 'i' to 's.length()'
    void findSubstrings(string s, int start, int n) {
        for(int end = start; end<n; end++) {
            if(isPalindrome(start, end, s)) {
                count++;
            }
        }
    }
    
    // Checks for a string to be a palindrome
    bool isPalindrome(int start, int end, string s) {
        while(start<=end) {
            if(s[start++]!=s[end--]) return false;
        }
        
        return true;
        
    }
    
    // Driver Function
    int countSubstrings(string s) {
        // Defines limits for checking a string is palindrome or not
        for(int i=0; i<s.length(); i++) {
            findSubstrings(s, i, s.length());
        }
        
        return count;
    }
};
