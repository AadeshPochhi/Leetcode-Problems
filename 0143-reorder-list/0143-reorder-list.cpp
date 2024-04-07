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
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=(fast->next)->next;
        }
        ListNode* prev=NULL;
        ListNode* curr=slow;
        ListNode* tmp;
        while(curr!=NULL){
            tmp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=tmp;
        }
        ListNode* first=head;
        ListNode* second=prev;
        while(second->next!=NULL){
            tmp=first->next;
            first->next=second;
            first=tmp;

            tmp=second->next;
            second->next=first;
            second=tmp;
        }
    }
};