// Problem: Delete Node in a Linked List
// Link: https://leetcode.com/problems/delete-node-in-a-linked-list/
// Time: O(1)
// Space: O(1)

// Approach:
// Since head is not accessible, copy the value of the next node into the current node,
// then bypass (delete) the next node.

class Solution {
public:
    void deleteNode(ListNode* node) {
        // Copy next node's value to current node
        node->val = node->next->val;
        
        // Save next node pointer for deletion
        ListNode* temp = node->next;
        
        // Link current node to next-to-next node
        node->next = node->next->next;
        
        // Free allocated memory.
        delete temp;
    }
};

//or
// node->prev = node->next; delete node

//ye approach won't work in SLL as usme sirfnext ptr hota


// ~~~~~~~~ Logic for DLL ~~~~~~~

// node->prev->next = node->next;
// node->next->prev = node->prev;
// delete node;