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
        while(end >=0 && s[end]!=' '){
            count++;
            end--;
        }
        return count;
    }
};

// MISTAKES to avoid:-
/*
1. its not end=='' but end=' ' ; {give a space inside ''}

2. You can't compare end to ' ' as end is a pointer  ~compare~ s[end]==' ';

3. Always check for 'end >=0'; so that it doesn't get out of string boundaries/ length;
*/