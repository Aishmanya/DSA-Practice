// Problem: Palindrome Linked List
// Link: https://leetcode.com/problems/palindrome-linked-list/
// Time: O(n)
// Space: O(1)

// Approach:
// 1. Find the middle of the linked list using Fast & Slow pointers.
// 2. Reverse the second half of the linked list.
// 3. Compare values of the first half and the reversed second half.
// 4. (Optional) Restore the list back to its original structure.


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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        // Step 1: Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        ListNode* secondHalfStart = reverseList(slow->next);

        // Step 3: Compare first half and reversed second half
        ListNode* p1 = head;
        ListNode* p2 = secondHalfStart;
        bool isPalindrome = true;

        while (p2 != nullptr) {
            if (p1->val != p2->val) {
                isPalindrome = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        // Step 4: Restore the list (Best Practice for interview production code)
        slow->next = reverseList(secondHalfStart);

        return isPalindrome;
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        return prev;
    }
};