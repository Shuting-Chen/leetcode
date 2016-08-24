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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       
        
        ListNode *p=head,*q=head;
        
        
        if(n==1 && !p->next)
        {
            return NULL;//return the pointer to the node, then I can return NULL I guess..
        }
        
        
        if(n==1 && !p->next->next)
        {
            p->next=NULL;
            return head;
        }
        
        if(n==2 && !p->next->next)
        {
            return head->next;
        }
        int i=0;
        
        while(i<n-1)
        {
            p=p->next;
            i++;
        }
        if(!p->next) 
        {
            return q->next;
        }
        
        while(p->next->next) 
        {
            p=p->next;
            q=q->next;
        }
        
        ListNode *qNext=q->next;
        q->next=qNext->next;
        
        return head;
    }
};
