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
    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* ptr=l1;
        if(l1->val>l2->val){
            ptr=l2;
            l2=l2->next;
        }
        else{
            l1=l1->next;
        }
        ListNode* t=ptr;
        while(l1 && l2){
            if(l1->val<l2->val){
                t->next=l1;
                l1=l1->next;
            }
            else{
                t->next=l2;
                l2=l2->next;
            }
            t=t->next;
        }
        if(!l1) t->next=l2;
        else t->next=l1;
        
        return ptr;
        
    }
    ListNode* mid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* sortAll(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* midptr=mid(head);
        ListNode* h1=head;
        ListNode* h2=midptr->next;
        midptr->next=NULL;
        ListNode* left=sortAll(h1);
        ListNode* right=sortAll(h2);
        h1=mergeTwoLists(left,right);
        return h1;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        return sortAll(head);
    }
};