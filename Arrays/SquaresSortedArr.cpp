// Problem: Squares of a Sorted Array
// Link: https://leetcode.com/problems/squares-of-a-sorted-array/
// Time: O(n)
// Space: O(1) -> If we don't count the output array memory.

// Approach:
// Use two pointers at both extreme ends (left and right) of the array.
// Compare the squares of the numbers at both pointers.
// Place the larger square at the end of the result array and move that pointer inward.

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        int left = 0;
        int right = n - 1;
        
        // Fill the answer array from back to front
        for (int i = n - 1; i >= 0; i--) {
            int left_square = nums[left] * nums[left];
            int right_square = nums[right] * nums[right];
            
            if (left_square > right_square) {
                ans[i] = left_square;
                left++; // Move left pointer forward
            } else {
                ans[i] = right_square;
                right--; // Move right pointer backward
            }
        }
        
        return ans;
    }
};


// OR 

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int i=0,j=n-1;
        for (int k=n-1; k>=0; k--){
            if(abs(nums[i])>abs(nums[j])){
                // swap(sq(nums[i]),nums[j]);
                ans[k]=(nums[i]*nums[i]);
                i++;
            }
            else{
                ans[k]=(nums[j]*nums[j]);
                j--;
            }
        }
        return ans;
    }
};