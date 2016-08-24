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
    
    struct compNode{
        bool operator()(ListNode *p,ListNode *q)
        {
            return p->val > q->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <ListNode *,vector<ListNode *>,compNode> mypq;
        //insert the 
      
        ListNode *dummy=new ListNode(0);
        ListNode *tail=dummy; //dummy won't change, so use the dummy->next to do the work..
        int k=lists.size();
        for(int i=0;i<k;i++)
        {
            //cause the things in the list is pointers, no matter it has something or not I can always get to it.
            if(lists[i])
            {
                mypq.push(lists[i]);
            }
        }
        
        //priority queue also have top() and push()..and pq.pop() also get rid of the top element.
        //if there is another listNode* in the top(),then insert it. 
        
        while(!mypq.empty())
        {
            tail->next=mypq.top();
            tail=tail->next;
            mypq.pop();
            if(tail->next)
            mypq.push(tail->next);
        }
        
        return dummy->next;
    }
};
