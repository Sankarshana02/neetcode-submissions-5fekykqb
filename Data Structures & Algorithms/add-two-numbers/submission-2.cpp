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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* dummyNode= new ListNode(-1);
        ListNode* curr=dummyNode;
        ListNode* t1=l1;
        ListNode* t2=l2;
        
        while(t1 || t2){
            int x= (t1 ? t1->val :0);
            int y=(t2 ? t2->val: 0);
            int sum=x+y+carry;
            carry=sum/10;
            int value=sum%10;
            curr->next=new ListNode(value);
            curr=curr->next;
            if(t1) t1=t1->next;
            if(t2) t2=t2->next;
        }

        if(carry){
            curr->next=new ListNode(carry);
            curr=curr->next;
        }

        return dummyNode->next;

        
    }
};
