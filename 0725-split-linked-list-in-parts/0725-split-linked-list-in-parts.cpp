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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* t=head;
        int n=0;
        while(t!=NULL){
            t=t->next;
            n++;
        }
        int r=n%k;
        int q=n/k;
        vector<int> len(k,q);
        for(int i=0;i<r;i++){
            len[i]++;
        }
        t=head;
        vector<ListNode*>ans(k);
        for(int i=0;i<k;i++){
            ans[i]=t;
            int j=0;
            ListNode* prev=NULL;
            while(j<len[i]){
                prev=t;
                t=t->next;
                j++;
            }
            if(prev)
            prev->next=NULL;
        }
        return ans;
    }
};