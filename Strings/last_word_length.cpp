// Problem: Length of Last Word
// Link: https://leetcode.com/problems/length-of-last-word/
// Time: O(n)
// Space: O(1)

// Approach:
// Iterate backwards from the end of the string.
// Skip any trailing spaces first.
// Count characters of the last word until another space is encountered or the beginning of string is reached.




class Solution {
public:
    int lengthOfLastWord(string s) {
        int end=s.length()-1;
        int count=0;

        while(end >=0 && s[end] == ' '){end--;}
        while(end >= 0 && s[end]!=' '){
            count++;
            end--;
        }
        return count;
    }
};