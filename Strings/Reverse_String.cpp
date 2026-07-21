// Problem: Reverse String
// Link: https://leetcode.com/problems/reverse-string/
// Time: O(n)
// Space: O(1)

// Approach:
// Use two pointers starting from both ends of the character array.
// Swap elements at left and right pointers in-place, then move left inward and right inward.
// Stop when the pointers cross each other.

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left=0;
        int right=s.size()-1;
        while(left<right){
            swap(s[left],s[right]);
            left++;
            right--;
        }
    }
};