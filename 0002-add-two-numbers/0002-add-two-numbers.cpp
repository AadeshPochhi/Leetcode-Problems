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
        ListNode *ans=new ListNode(0);
        ListNode *toRet=ans;
        int carry=0;
        while(l1!=NULL && l2!=NULL){
            ans->next=new ListNode(0);
            ans=ans->next;
            int sum=l1->val + l2->val + carry;
            carry=sum/10;
            ans->val=sum%10;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
            ans->next=new ListNode(0);
            ans=ans->next;
            int sum=l1->val + carry;
            ans->val=sum%10;
            carry=sum/10;
            l1=l1->next;
        }
        while(l2!=NULL){
            ans->next=new ListNode(0);
            ans=ans->next;
            int sum=l2->val + carry;
            ans->val=sum%10;
            carry=sum/10;
            l2=l2->next;
        }
        if(carry){
            ans->next=new ListNode(carry);
        }
        return toRet->next;
    }
};