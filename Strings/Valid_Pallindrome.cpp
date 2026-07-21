// Problem: Valid Palindrome
// Link: https://leetcode.com/problems/valid-palindrome/
// Time: O(n)
// Space: O(1)

// Approach:
// Use two pointers starting from both ends of the string.
// Skip non-alphanumeric characters using isalnum().
// Convert valid characters to lowercase using tolower() and compare.
// If characters don't match, return false. If pointers meet without mismatch, return true.

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            // Skip non-alphanumeric characters from the left
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            // Skip non-alphanumeric characters from the right
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            
            // Compare characters after converting to lowercase
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
};