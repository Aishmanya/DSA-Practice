// Problem: Remove Nth Node From End of List
// Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Time: O(n)
// Space: O(1)

// Approach:
// Maintain a gap of (n + 1) nodes between 'fast' and 'slow' pointers.
// Advance 'fast' by (n + 1) steps first, then move both pointers together.
// When 'fast' hits NULL, 'slow' will point right before the node to be deleted.

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // Move fast pointer n + 1 steps ahead
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }

        // Move both pointers until fast hits the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete the nth node from the end
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete; // Free memory in C++

        return dummy.next;
    }
};