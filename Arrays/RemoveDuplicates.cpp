// Problem: Remove Duplicates from Sorted Array
// Link: [https://leetcode.com/problems/remove-duplicates-from-sorted-array/](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)
// Time: O(n)
// Space: O(1)

// Approach:
// Use a two-pointer technique.
// The slow pointer 'i' tracks the position of the last unique element found.
// The fast pointer 'j' scans the array to find new unique elements and move them forward to i.

class Solution {
public:
int removeDuplicates(vector& nums) {
int i=0;
for(int j=1;j<nums.size();j++){
if(nums[j] != nums[i]){
nums[i+1] = nums[j] ;
i++;
}
}
return i+1;
}
};