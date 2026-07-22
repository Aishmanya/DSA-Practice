// Problem: Reverse Words in a String
// Link: https://leetcode.com/problems/reverse-words-in-a-string/
// Time: O(n)
// Space: O(1) -> In-place string modification

// Approach:
// 1. Clean extra spaces in-place using two pointers (i for reading, index for writing).
// 2. Reverse the entire cleaned string to swap word positions.
// 3. Reverse each word individually to restore original letter order.

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0, j = 0;
        
        // Step 1: Clean spaces in-place
        int index = 0;
        while (i < n) {
            // Skip leading or extra spaces
            while (i < n && s[i] == ' ') i++;
            if (i >= n) break;
            
            // Add a single space between words (except before the first word)
            if (index > 0) s[index++] = ' ';
            
            // Copy the actual word
            while (i < n && s[i] != ' ') {
                s[index++] = s[i++];
            }
        }
        
        // Resize string to remove leftover trailing garbage characters
        s.resize(index);
        
        // Step 2: Reverse the entire cleaned string
        reverse(s.begin(), s.end());
        
        // Step 3: Reverse each individual word back
        int start = 0;
        for (int end = 0; end <= s.length(); end++) {
            if (end == s.length() || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }
        
        return s;
    }
};