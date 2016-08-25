/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        
        ListNode *p=new ListNode(0);
        p->next=head;
        head=p;
        while(p->next && p->next->next)
        {
            ListNode *first=p->next;
            ListNode *second=first->next;
            first->next=second->next;
            second->next=first;
            p->next=second;
            p=p->next->next;
        }
        return head->next;
    }
};
