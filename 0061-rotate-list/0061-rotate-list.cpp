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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head; 
        ListNode* t=head;
        ListNode* o=head;
        ListNode*ans;
        int n=0;
        while(t!=NULL){
            t=t->next;
            n++;
        }
        k%=n;
        t=head;
        if(k==0) return head;
        else{
            for(int i=0;i<(n-k)-1;i++){
                t=t->next;
            }
            for(int i=0;i<n-1;i++){
                o=o->next;
            }
            ans=t->next;
            t->next=NULL;
            o->next=head;
        }
        return ans;
    }
};