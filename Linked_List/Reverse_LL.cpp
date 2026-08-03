// Problem: Reverse Linked List
// Link: https://leetcode.com/problems/reverse-linked-list/
// Time: O(n)
// Space: O(1)

// Approach:-
// Maintain three pointers: prev (NULL), curr (head), and next.
// Iteratively break the forward link and point curr->next back to prev.
// Advance prev and curr until curr becomes NULL. Return prev as the new head.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while(curr != nullptr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;

    }
};