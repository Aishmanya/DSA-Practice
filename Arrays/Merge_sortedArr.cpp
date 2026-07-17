// Problem: Merge Sorted Array
// Link: https://leetcode.com/problems/merge-sorted-array/
// Time: O(m + n)
// Space: O(1)

// Approach:
// Use three pointers starting from the back.
// Compare elements from the end of both arrays and place the larger one at the last available slot of nums1.
// If any elements remain in nums2, copy them over to the front of nums1.


#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p1 = m - 1;         // Pointer for valid elements in nums1
    int p2 = n - 1;         // Pointer for nums2
    int i = m + n - 1;      // Pointer for the placement slot at the back

    // Compare elements from the back and move the larger one to the end
    while (p1 >= 0 && p2 >= 0) {
        if (nums1[p1] > nums2[p2]) {
            nums1[i] = nums1[p1];
            p1--;
        } else {
            nums1[i] = nums2[p2];
            p2--;
        }
        i--;
    }

    // If there are remaining elements in nums2, copy them over.
    // (If nums1 has remaining elements, they are already in their correct places!)
    while (p2 >= 0) {
        nums1[i] = nums2[p2];
        p2--;
        i--;
    }
}

/*
  TIME COMPLEXITY: O(m + n)
  We iterate through both arrays exactly once from back to front.

  SPACE COMPLEXITY: O(1)
  We modify nums1 completely in-place, using zero extra memory structure.
*/