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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return NULL;
        int length=0;
        ListNode* temp=head;
        while(temp){
            length++;
            temp=temp->next;
            
        }

        if(length==n) return head->next;
        int revLength=length-n;
        int cnt=0;
        temp=head;
        while(cnt!=revLength-1){
            temp=temp->next;
            cnt++;
        }
        ListNode* delNode=temp->next;
        
        if(temp->next->next){
            ListNode* frontNode=temp->next->next;
            temp->next=frontNode;
        }
        else{
            temp->next=nullptr;
        }
        delete(delNode);

        return head;
        
    }
};
