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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *d=new ListNode(0,head);
        ListNode *prev=d;
        while(head!=NULL){
            ListNode* temp=head->next;
            while(temp!=NULL && head->val==temp->val){
                ListNode *t=temp->next;
                delete(temp);
                temp=t;
            }
            if(head->next==temp){
                prev=head;
            }
            else{
                prev->next=temp;
                delete(head);
            }
            head=temp;
        }
        return d->next;
    }
};