// Problem: Happy Number
// Link: https://leetcode.com/problems/happy-number/
// Time: O(log n) -> Sum of digits shrinks logarithmically
// Space: O(log n) -> To store seen numbers in the hash set

// Approach:-
// Use a helper function to calculate the sum of squares of digits.
// Keep track of visited numbers using an unordered_set to detect infinite cycles.
// If the number reduces to 1, return true. If a repeated number is found in the set, return false.

class Solution {
private:
    // Helper function to calculate sum of squares of digits
    int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int digit = n % 10;
            totalSum += digit * digit;
            n /= 10;
        }
        return totalSum;
    }

public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        
        while (n != 1 && !seen.count(n)) {
            seen.insert(n);
            n = getNext(n);
        }
        
        return n == 1;
    }
};