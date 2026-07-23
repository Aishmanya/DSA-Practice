// Problem: Longest Substring Without Repeating Characters
// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1); // Direct lookup table for ASCII characters
        int n = s.size();
        int l = 0, r = 0;
        int maxLen = 0;

        while (r < n) {
            // Check if the character has been seen AND lies within current window [l, r]
            if (hash[s[r]] != -1) {
                if (hash[s[r]] >= l) {
                    l = hash[s[r]] + 1; // Direct jump to collapse invalid window
                }
            }

            int len = r - l + 1;
            maxLen = max(maxLen, len);

            hash[s[r]] = r; // Store/Update latest index of character
            r++;            // Move right pointer forward
        }

        return maxLen;
    }
};

// hash table basically stores the chars along with the indexes where they have appeared last