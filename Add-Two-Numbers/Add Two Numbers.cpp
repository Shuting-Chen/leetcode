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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
        
        if(!l1 && !l2) return NULL;
        int carry=0;
        ListNode *cur=new ListNode(0);
        ListNode *result=cur;
        while(l1 && l2)
        {
            //everytime Need to new a new ListNode;
            int newVal=l1->val+l2->val+carry;
            cur->next=new ListNode(newVal%10);
            carry=newVal/10;
            l1=l1->next;
            l2=l2->next;
            cur=cur->next; 
        }
        while(l1)
        {
              
            cur->next=new ListNode((l1->val+carry)%10);
            carry=(l1->val+carry)/10;
            l1=l1->next;
            cur=cur->next;
        }
        while(l2)
        { 
            cur->next=new ListNode((l2->val+carry)%10);
            carry=(l2->val+carry)/10;
            l2=l2->next;
            cur=cur->next;
        }
        if(carry>0)
        {
            cur->next=new ListNode(carry%10);
        }
        return result->next;
    }
};
