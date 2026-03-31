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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;

        // check if k nodes exist
        int count = 0;
        while (curr && count < k) {
            curr = curr->next;
            count++;
        }

        if (count < k) return head;

        // reverse first k nodes
        ListNode* newHead = reverse(head, k);

        // head is now tail of reversed group
        head->next = reverseKGroup(curr, k);

        return newHead;
    }

private:
    ListNode* reverse(ListNode* head, int k) {
        if (k == 1) return head;

        ListNode* newHead = reverse(head->next, k - 1);

        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};