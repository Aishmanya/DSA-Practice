// Problem: Valid Anagram
// Link: https://leetcode.com/problems/valid-anagram/
// Time: O(n)
// Space: O(1) -> Fixed size array of 26 integers for lowercase alphabet counts

// Approach:
// If string lengths differ, they cannot be anagrams.
// Use a fixed size array (size 26) to track character frequencies.
// Increment count for characters in 's' and decrement for characters in 't'.
// If all frequency counts remain zero, the strings are valid anagrams.

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Step 1: Base condition check
        if (s.length() != t.length()) {
            return false;
        }
        
        // Frequency table for 26 lowercase English letters initialized to 0
        vector<int> count(26, 0);
        
        // Step 2: Update frequencies in a single pass
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        
        // Step 3: Check if all character counts balance out to 0
        for (int val : count) {
            if (val != 0) {
                return false;
            }
        }
        
        return true;
    }
};